
#include <iostream>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int i, float salaire) {
        nom = n;
        id = i;
        salaireDeBase = salaire;
    }

    virtual void afficherInfos() {
        cout << "Nom : " << nom << endl;
        cout << "ID : " << id << endl;
        cout << "Salaire de base : "
             << salaireDeBase << " DH" << endl;
    }

    virtual ~Employe() {
        cout << "Destruction de l'employe : "
             << nom << endl;
    }
};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float salaire, float prime)
        : Employe(n, i, salaire) {
        primeAnnuelle = prime;
    }

    void afficherInfos() override {
        cout << "\n--- Employe permanent ---" << endl;
        Employe::afficherInfos();
        cout << "Prime annuelle : "
             << primeAnnuelle << " DH" << endl;
    }
};

class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    Contractuel(string n, int i, float salaire,
                int duree, float taux)
        : Employe(n, i, salaire) {
        dureeContrat = duree;
        tauxHoraire = taux;
    }

    float calculerSalaireMensuel(int heures) {
        return heures * tauxHoraire;
    }

    void afficherInfos() override {
        cout << "\n--- Employe contractuel ---" << endl;
        Employe::afficherInfos();
        cout << "Duree du contrat : "
             << dureeContrat << " mois" << endl;
        cout << "Taux horaire : "
             << tauxHoraire << " DH" << endl;
    }
};

int main() {
    // Tableau dynamique de pointeurs vers Employe
    Employe* employes[3];

    employes[0] = new Permanent(
        "Sara", 101, 6000, 8000
    );

    employes[1] = new Contractuel(
        "Youssef", 102, 0, 12, 50
    );

    employes[2] = new Permanent(
        "Amine", 103, 7500, 10000
    );

    // Polymorphisme
    for (int i = 0; i < 3; i++) {
        employes[i]->afficherInfos();
    }

    // Calcul du salaire du contractuel
    Contractuel* c =
        dynamic_cast<Contractuel*>(employes[1]);

    if (c != nullptr) {
        cout << "\nSalaire mensuel de Youssef : "
             << c->calculerSalaireMensuel(160)
             << " DH" << endl;
    }

    // Liberation de la memoire
    for (int i = 0; i < 3; i++) {
        delete employes[i];
    }

    return 0;
}
