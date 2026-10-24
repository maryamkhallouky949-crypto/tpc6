
#include <iostream>
#include <string>
using namespace std;

class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(string n, double p) {
        nom = n;
        prix = p;
    }

    virtual void afficherInfos() {
        cout << "Nom : " << nom << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }

    virtual ~Produit() {
    }
};

class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(string n, double p, string date)
        : Produit(n, p) {
        dateExpiration = date;
    }

    void afficherInfos() override {
        cout << "--- Produit alimentaire ---" << endl;
        Produit::afficherInfos();
        cout << "Date d'expiration : "
             << dateExpiration << endl;
    }
};

class ProduitElectronique : public Produit {
private:
    int garantie;

public:
    ProduitElectronique(string n, double p, int g)
        : Produit(n, p) {
        garantie = g;
    }

    void afficherInfos() override {
        cout << "--- Produit electronique ---" << endl;
        Produit::afficherInfos();
        cout << "Garantie : " << garantie
             << " ans" << endl;
    }
};

int main() {
    ProduitAlimentaire p1("Lait", 8.5, "30/11/2026");
    ProduitElectronique p2("Ordinateur", 6500, 2);

    p1.afficherInfos();

    cout << endl;

    p2.afficherInfos();

    return 0;
}
