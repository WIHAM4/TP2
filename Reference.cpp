/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * \file Reference.cpp
 * \brief Implementation de la classe Reference
 * \author William Hamilton
 * \date 4 octobre 2021, 18:41
 */

#include "Reference.h"
#include "validationFormat.h"
#include <sstream>
#include <iostream>

using namespace std;


/**
 * \brief Constructeur avec parametre qui demande la reference bibliographique
 * \param[in] p_auteur L'auteur de l'oeuvre
 * \param[in] p_titre Le titre de l'oeuvre
 * \param[in] p_annee L'annee de sortie
 * \param[in] p_identifiant Code ISSN ou ISBN de la reference
 * \return Un objet reference
 */
Reference::Reference (std::string p_auteur, std::string p_titre, int p_annee, std::string p_identifiant) : m_auteur (p_auteur), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant) { }


/**
 * \brief Accesseur pour l'auteur
 * \return m_auteur L'auteur de l'objet
 */
string
Reference::reqAuteur () const
{
  return m_auteur;
}


/**
 * \brief Accesseur pour le titre
 * \return m_titre Le titre de l'objet
 */
string
Reference::reqTitre () const
{
  return m_titre;
}


/**
 * \brief Accesseur l'annee
 * \return m_annee L'annee de l'objet
 */
int
Reference::reqAnnee () const
{
  return m_annee;
}


/**
 * \brief Accesseur pour l'identifiant
 * \return m_heure L'identifiant de l'objet
 */
string
Reference::reqIdentifiant () const
{
  return m_identifiant;
}


/**
 * \brief Mutateur pour annee, modifie l'annee
 * \param[in] p_annee nouvel annee
 */
void
Reference::asgAnnee (int p_annee)
{
  m_annee = (p_annee > 0);
}


/**
 *
 * \return La reference complete sous la forme d'une chaine de caractères
 */
string
Reference::reqReferenceFormate () const
{
  ostringstream os;
  os << m_auteur << ',' << m_titre << ',' << m_annee << ',' << m_identifiant << endl;

  return os.str ();
}