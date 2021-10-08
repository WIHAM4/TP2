/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>

/**
 * \class Reference
 * \brief Classe Reference permet de modéliser des références bibliographiques.
 */

#ifndef REFERENCE_H
#define REFERENCE_H

class Reference
{
public:
  Reference ();
  Reference (std::string p_auteur, std::string p_titre, int p_annee, std::string p_identifiant);

  std::string reqAuteur () const;
  std::string reqTitre () const;
  int reqAnnee () const;
  std::string reqIdentifiant () const;

  std::string reqReferenceFormate () const;

  void asgAuteur (std::string p_auteur);
  void asgTitre (std::string p_titre);
  void asgAnnee (int p_annee);
  void asgIdentifiant (std::string p_identifiant);

private:
  std::string m_auteur;
  std::string m_titre;
  int m_annee;
  std::string m_identifiant;

};

#endif /* REFERENCE_H */

