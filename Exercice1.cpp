
#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    int age;

public:
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

class Etudiant : public Personne {
private:
    string niveau;

public:
    Etudiant(string n, int a, string niv)
        : Personne(n, a) {
        niveau = niv;
    }

    void afficher() {
        Personne::afficher();
        cout << "Niveau : " << niveau << endl;
    }
};

int main() {
    Etudiant e("Sara", 21, "S5");

    e.afficher();

    return 0;
}
