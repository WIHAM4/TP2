/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 13 septembre 2021, 21:17
 */

#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include "validationFormat.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

namespace util
{


  bool
  validerFormatNom (const std::string& p_nom)
  {

    bool valide = true;

    int compteur = 0;

    for (auto i : p_nom) //Verification de chaque charactere.
      {
        compteur += 1;
      }

    char nom [compteur + 1];

    strcpy (nom, p_nom.c_str ());

    for (int i = 0; i < compteur; i++)
      {
        if (isdigit (nom[i])) //Verification lettre
          {
            valide = false;
          }
        else
          {

            if (p_nom[i] == '-' and p_nom[i + 1] == '-' ) //Verification "--"
              {
                valide = false;
              }

            if (p_nom[i] == ' ' and p_nom[i + 1] == '-' ) //Verification " -"
              {
                valide = false;
              }

            if (p_nom[i] == '-' and p_nom[i + 1] == ' ' ) //Verification "- "
              {
                valide = false;
              }
            if (p_nom[i] == ' ' and p_nom[i + 1] == ' ' ) //Verification "- "
              {


                valide = false;
              }
          }
      }
    return valide;
  }


  bool
  validerCodeIssn (const std::string & p_issn)
  {
    bool valide = false;

    istringstream iss (p_issn);
    string issn;
    iss >> issn;

    string codeISSN = "ISSN";
    size_t indexISSN = p_issn.find (codeISSN);

    string codeChiffre;
    iss >> codeChiffre;

    int compteur = 8;
    int addition = 0;
    int longueur = p_issn.length ();

    if (all_of (issn.begin (), issn.end (), [](unsigned char c)
        {
          return isupper (c);
        }))

    {
      if (indexISSN != std::string::npos)
        {
          if (indexISSN == 0)
            {

              if (longueur == 14)
                {

                  if (p_issn[9] == '-')//Verifier si "-" est a la bonne position
                    {

                      for (int i = 0; i < 8; i++)
                        {
                          if (i == 4)
                            {
                              continue;
                            }
                          else
                            {
                              char monChar = codeChiffre[i];

                              int monInt = monChar - '0';
                              addition += monInt * (compteur);
                              compteur -= 1;
                            }
                        }


                      if ((addition % 11) == 0)
                        {
                          if (p_issn[13] == '0')
                            {
                              valide = true;
                            }
                        }

                      else
                        {
                          int cle = (11 - addition % 11);
                          char maCleStr = p_issn[13];
                          int maCleInt = maCleStr - '0';


                          if (cle == (maCleInt))
                            {


                              valide = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return valide;
  }


  bool
  validerCodeIsbn (const std::string & p_isbn)
  {
    bool valide = false;

    istringstream iss (p_isbn);
    string isbn;
    iss >> isbn;

    string codeISBN = "ISBN";
    size_t indexISBN = p_isbn.find (codeISBN);

    string codeChiffre;
    iss >> codeChiffre;

    int addition = 0;
    int longueur = p_isbn.length ();

    if (all_of (isbn.begin (), isbn.end (), [](unsigned char c)
        {
          return isupper (c);
        }))

    {
      if (indexISBN != std::string::npos)
        {
          if (indexISBN == 0) //Verifier ISSN
            {
              if (isspace (p_isbn[4])) //Verifier espace entre ISBN et les chiffres
                {
                  if (count (p_isbn.begin (), p_isbn.end (), '-') == 4)
                    {
                      codeChiffre.erase (remove (codeChiffre.begin (), codeChiffre.end (), '-'), codeChiffre.end ());

                      if (longueur == 22) //Verifier longueur du code

                        {
                          if (codeChiffre[0] == '9' and codeChiffre[1] == '7' and (codeChiffre[0] == '8' or codeChiffre[0] == '9')) //Verifier les 3 premiers chiffres
                            {
                              for (int i = 0; i < 12; i++) // Verifier la cle
                                {
                                  char mon1erChar = codeChiffre[i];
                                  int mon1erInt = mon1erChar - '0';

                                  if ((i % 2) == 0)
                                    {
                                      addition += mon1erInt * (1);
                                    }
                                  else

                                    addition += mon1erInt * (3);


                                }
                            }
                        }
                    }

                  if ((addition % 10) == 0)
                    {
                      if (codeChiffre[16] == '0')
                        {
                          valide = true;
                        }
                    }

                  else
                    {
                      int cle = (10 - addition % 10);
                      char maCleStr = codeChiffre[16];
                      int maCleInt = maCleStr - '0';

                      if (cle == (maCleInt))
                        {
                          valide = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < longueur; i++) // Test s'il y a un 22
      {
        if (p_isbn[i] == '-')
          {
            continue;
          }
        else
          {
            char mon1erChar = p_isbn[i];
            int mon1erInt = mon1erChar - '0';

            char mon2eChar = p_isbn[i + 1];
            int mon2eInt = mon2eChar - '0';

            if (mon1erInt == 2 and mon2eInt == 2)
              {
                valide = false;
              }
          }
      }

    if (p_isbn[8] == ' ') // Test sur tiret apres 3 premiers chiffres
      {
        valide = false;
      }

    return valide;
  }
}