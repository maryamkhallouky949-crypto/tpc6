
#include <iostream>
#include <string>
using namespace std;

class Compte {
protected:
    string numero;
    double solde;

public:
    Compte(string num, double s) {
        numero = num;
        solde = s;
    }

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot effectue." << endl;
        } else {
            cout << "Montant invalide." << endl;
        }
    }

    void retirer(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide." << endl;
        } else if (montant <= solde) {
            solde -= montant;
            cout << "Retrait effectue." << endl;
        } else {
            cout << "Solde insuffisant." << endl;
        }
    }

    void afficherSolde() {
        cout << "Numero : " << numero << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    CompteEpargne(string num, double s, double taux)
        : Compte(num, s) {
        tauxInteret = taux;
    }

    double calculerInteret() {
        return solde * tauxInteret / 100.0;
    }
};

int main() {
    CompteEpargne c("C001", 2000, 5);

    cout << "Solde initial :" << endl;
    c.afficherSolde();

    c.deposer(500);
    c.retirer(200);

    cout << "\nApres les operations :" << endl;
    c.afficherSolde();

    cout << "Interet : "
         << c.calculerInteret() << " DH" << endl;

    return 0;
}
