#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;



class plata_numerar
{
    protected:
        int suma;
        string valuta;
        string data;
    public:
        plata_numerar(int s = 0, string val = "euro", string d = "*Data necunoscuta*"){this -> suma = s; this -> valuta = val; this -> data = d;}
        plata_numerar(plata_numerar *);
        virtual ~plata_numerar(){};
        plata_numerar& operator =(const plata_numerar&);
        plata_numerar& operator =(int);
        friend void citire(plata_numerar*);
        virtual void afisare();
        int get_suma(){return this -> suma;}
        string get_valuta(){return this -> valuta;}
        string get_data(){return this->data;}
        void set_suma(int i){this -> suma = i;}
        void set_valuta(string v){this -> valuta = v;}
        void set_data(string d){this -> data = d;}

};




plata_numerar::plata_numerar(plata_numerar* plata)
{
    this -> suma = plata -> suma;
    this -> valuta = plata -> valuta;
    this -> data = plata -> data;
}


void plata_numerar::afisare()
{
    cout << "Plata a fost efectuata: Suma de " << this -> suma << " " << this -> valuta << " la data de " << this -> data <<".\n";

}


plata_numerar& plata_numerar::operator = (const plata_numerar &p)
{
    if (this != &p){
        this -> suma = p.suma;
        this -> valuta = p.valuta;
        this -> data = p.data;
    }

    return *this;
}

plata_numerar& plata_numerar::operator = (int x)
{
    if (this -> suma != x){
        this -> suma = x;
        this -> valuta = "euro";
        this -> data = "*Data necunoscuta*";
    }

    return *this;
}

void citire(plata_numerar *p)
{

    cout << "Introduceti suma pentru plata: ";
    cin >> p -> suma;
    cout << "Introduceti valuta sumei: ";
    cin >> p -> valuta;
    cout << "Introduceti data platii: ";
    cin.ignore();
    getline(cin,p -> data);


}

class plata_cec : public plata_numerar
{
    protected:
        string nume;
        string cont_bancar;
    public:
        plata_cec(string n = "anonim", string c = "cont necunoscut"):plata_numerar(){this -> nume = n; this -> cont_bancar = c;}
        virtual ~plata_cec(){};
        plata_cec(plata_cec *);
        plata_cec& operator =(const plata_cec&);
        plata_cec& operator =(int);
        void afisare();
        friend void citire(plata_cec*);
        string get_nume(){return this -> nume;}
        string get_cont(){return this -> cont_bancar;}
        void set_nume(string n){this -> nume = n;}
        void set_cont(string c){this -> cont_bancar = c;}


};


plata_cec :: plata_cec (plata_cec* plata)
{
    this -> suma = plata -> suma;
    this -> valuta = plata -> valuta;
    this -> data = plata -> data;
    this -> nume = plata -> nume;
    this -> cont_bancar = plata -> cont_bancar;
}



plata_cec& plata_cec::operator = (const plata_cec &p)
{
    if (this != &p){
        this -> suma = p.suma;
        this -> valuta = p.valuta;
        this -> data = p.data;
        this -> nume = p.nume;
        this -> cont_bancar = p.cont_bancar;
    }

    return *this;
}

plata_cec& plata_cec::operator = (int x)
{
    if (this -> suma != x){
        this -> suma = x;
        this -> valuta = "euro";
        this -> data = "*Data necunoscuta*";
        this -> nume = "anonim";
        this -> cont_bancar = "cont necunoscut";
    }

    return *this;
}

void plata_cec :: afisare()
{
    plata_numerar :: afisare();
    cout << "Numele: " << this -> nume << ".\n";
    cout << "Din contul: " << this -> cont_bancar << "\n";
}


void citire(plata_cec* p)
{
    cout << "Introduceti suma pentru plata: ";
    cin >> p -> suma;
    cout << "Introduceti valuta sumei: ";
    cin >> p -> valuta;
    cout << "Introduceti data platii: ";
    cin.ignore();
    getline(cin,p -> data);
    cout << "Introduceti numele dumneavoastra: ";
    getline(cin,p -> nume);
    cout << "Introduceti contul dumneavoastra: ";
    cin >> p -> cont_bancar;


}




class plata_card:public plata_cec
{
    protected:
        string id_card;
    public:
        virtual ~plata_card(){};
        plata_card(plata_card* );
        plata_card(string id = "ID Necunoscut"):plata_cec(){this -> id_card = id;}
        plata_card& operator =(const plata_card&);
        plata_card& operator =(int);
        void afisare();
        friend void citire(plata_card*);
        string get_id(){return this -> id_card;}
        void set_id(string id){this -> id_card = id;}


};


plata_card :: plata_card (plata_card* plata)
{
    this -> suma = plata -> suma;
    this -> valuta = plata -> valuta;
    this -> data = plata -> data;
    this -> nume = plata -> nume;
    this -> cont_bancar = plata -> cont_bancar;
    this -> id_card = plata -> id_card;
}

plata_card& plata_card::operator = (const plata_card &p)
{
    if (this != &p){
        this -> suma = p.suma;
        this -> valuta = p.valuta;
        this -> data = p.data;
        this -> nume = p.nume;
        this -> cont_bancar = p.cont_bancar;
        this -> id_card = p.id_card;
    }

    return *this;
}

plata_card& plata_card::operator = (int x)
{
    if (this -> suma != x){
        this -> suma = x;
        this -> valuta = "euro";
        this -> data = "*Data necunoscuta*";
        this -> nume = "anonim";
        this -> cont_bancar = "cont necunoscut";
        this -> id_card = "numar card necunoscut";
    }

    return *this;
}

void plata_card :: afisare()
{
    plata_cec :: afisare();
    cout << "Numarul cardului de credit: " << this -> id_card << "\n";
}


void citire(plata_card* p)
{
    cout << "Introduceti suma pentru plata: ";
    cin >> p -> suma;
    cout << "Introduceti valuta sumei: ";
    cin >> p -> valuta;
    cout << "Introduceti data platii: ";
    cin.ignore();
    getline(cin,p -> data);
    cout << "Introduceti numele dumneavoastra: ";
    getline(cin,p -> nume);
    cout << "Introduceti contul dumneavoastra: ";
    cin >> p -> cont_bancar;
    cout << "Introduceti numarul cardului: ";
    cin >> p -> id_card;;


}


template <class T>
class Gestiune
{

    protected:
        vector <T> plati;
        int numar_clienti;


    public:
        Gestiune<T>();
        Gestiune<T>& operator += (T*);
        Gestiune<T>(const Gestiune<T>& ob)
        {
            for(auto &it : ob.plati)
            {
                plati.push_back(new T(*it));
            }
            numar_clienti = ob.numar_clienti;
        }
        Gestiune<T>& operator = (const Gestiune<T>& ob)
        {
            for(auto& it: ob.plati)
            {
                delete it;
            }
            plati.clear();
            for(auto& it: ob.plati)
            {
                plati.push_back(new T(*it));
            }
            numar_clienti = ob.numar_clienti;
        }
        void afis()
        {
            cout << "Numar clienti: " << get_clienti() << "\n";
            int s = 0;
            for (auto& it : plati)
            {
                s += it -> get_suma();
            }
            cout << "Suma totala este: " << s << "\n";
            cout << get_clienti() << "\n";
            for(auto &it : plati)
            {
                it -> afisare_date();
            }
        }

        const int& get_clienti() const
        {
            return numar_clienti;
        }

};


template <class T>
Gestiune<T> :: Gestiune() : numar_clienti(0)
{

}


template <class T>
Gestiune<T>& Gestiune<T> :: operator += (T* plata)
{
    numar_clienti += 1;
    T* pt = new T;
    pt = plata;
    plati.push_back(pt);
    return *this;
}



template <>
class Gestiune<plata_card>
{
    protected:
        unordered_set<string> clienti;
        vector <plata_card*> plati;
        int numar_clienti;

    public:
        Gestiune(){numar_clienti = 0;}
        Gestiune<plata_card> & operator =(const Gestiune<plata_card>& ob)
        {
            clienti.clear();
            for(auto &it: ob.clienti)
            {
                clienti.insert(it);
            }
            for(auto &it: ob.plati)
            {
                delete it;
            }
            plati.clear();
            for(auto& it: ob.plati)
            {
                plati.push_back(new plata_card(*it));
            }
            numar_clienti = ob.numar_clienti;
            return *this;
        }

        Gestiune<plata_card>(const Gestiune<plata_card>& ob)
        {
            for(auto &it : ob.clienti)
            {
                clienti.insert(it);
            }
            for(auto &it : ob.plati)
            {
                plati.push_back(new plata_card(*it));
            }
            numar_clienti = ob.numar_clienti;
        }

        Gestiune<plata_card> & operator += (plata_card*& p)
        {
            numar_clienti += 1;
            plata_card *pt = new plata_card(*p);
            plati.push_back(pt);
            clienti.insert(p -> get_nume());
            numar_clienti = clienti.size();
            return *this;
        }

        void afis()
        {
            cout << "Clienti: " << "\n";
            for(auto& it : clienti)
            {
                cout << it << "\n";
            }
        }

        const int& get_clienti() const
        {
            return numar_clienti;
        }

};


class firma
{
    protected:
        string nume;
        unordered_map<int, plata_numerar*> plati;
        Gestiune<plata_card> card;
        Gestiune<plata_cec> cec;
        Gestiune<plata_numerar> numerar;
        static int id_plata;
        int id;
    public:
        firma(string n = "Nume necunoscut"){this -> nume = n;}
        string get_nume(){return nume;}
        void set_nume(string n){this -> nume = n;}
        void plata_noua(string = "Tip plata necunoscut");
        void afisare_plati();
        static void afisare_numar_plati();
        firma& operator = (const firma&);


};

int firma :: id_plata = 0;

void firma :: plata_noua(string t)
{
    if(t != "card" && t != "cec" && t != "numerar")
    {
        throw "Tip plata invalid. Mai incercati o data\n\n";
    }

    if(t == "numerar")
    {
        plata_numerar *pn = new plata_numerar;
        citire(pn);
        if(pn -> get_data() == "*Data necunoscuta*")
        {
            throw "Data incorecta. Mai incercati o data\n\n";
        }
        if(pn -> get_suma() < 0)
        {
            throw "Suma este prea mica. Mai incercati o data\n\n";
        }
        id_plata += 1;
        id = id_plata;
        plati[id] = pn;
        numerar += pn;
    }

    if(t == "cec")
    {
        plata_cec *pc = new plata_cec;
        citire(pc);
        if(pc -> get_nume() == "anonim")
        {
            throw "Nume incorect. Mai incercati o data\n\n";
        }
        if(pc -> get_data() == "*Data necunoscuta*")
        {
            throw "Data incorecta. Mai incercati o data\n\n";
        }
        if(pc -> get_suma() < 0)
        {
            throw "Suma este prea mica. Mai incercati o data\n\n";
        }
        id_plata += 1;
        id = id_plata;
        plati[id] = pc;
        cec += pc;
    }
    if(t == "card")
    {
        plata_card *pc = new plata_card;
        citire(pc);
        if(pc -> get_nume() == "anonim")
        {
            throw "Nume incorect. Mai incercati o data\n\n";
        }
        if(pc -> get_data() == "*Data necunoscuta*")
        {
            throw "Data incorecta. Mai incercati o data\n\n";
        }
        if(pc -> get_suma() < 0)
        {
            throw "Suma este prea mica. Mai incercati o data\n\n";
        }
        if(pc -> get_cont() == "cont necunoscut")
        {
            throw "Contul bancar nu a fost introdus. Mai incercati o data\n\n";
        }
        if(pc -> get_id() == "numar card necunoscut")
        {
            throw "Numarul cardului nu a fost introdus. Mai incercati o data\n\n";
        }
        id_plata += 1;
        id = id_plata;
        plati[id] = pc;
        card += pc;
    }
}



void firma :: afisare_plati()
{
    for(auto &it: plati)
    {
        cout << "Plata " << it.first << "\n";
        it.second -> afisare();
        cout << "\n";
    }
}

void firma :: afisare_numar_plati()
{
    cout << "Numarul de plati este " << firma :: id_plata << "\n";
}

int main()
{



    /*plata_numerar A;
    plata_numerar B;
    A = 1000;
    A.afisare();
    B = A;
    B.afisare();
    plata_cec C;
    C = 1000;
    C.afisare();
    plata_cec D;
    citire(&D);
    D.afisare();
    plata_card card;
    citire(&card);
    card.afisare();
    plata_card CC;
    CC = 1000;
    CC.afisare();
    cout << "\n\n";*/

    firma f;
    string tip;
    cout << "Introduceti tipul platii(card, cec, numerar): ";
    cin >> tip;
    try
    {
        f.plata_noua(tip);
    }
    catch(const char *error)
    {
        cout << error;
    }
    f.afisare_numar_plati();
    f.afisare_plati();
    cout << "Introduceti tipul platii(card, cec, numerar): ";
    cin >> tip;
    f.plata_noua(tip);
    f.afisare_numar_plati();
    f.afisare_plati();
    cout << "Introduceti tipul platii(card, cec, numerar): ";
    cin >> tip;
    f.plata_noua(tip);
    f.afisare_numar_plati();
    f.afisare_plati();



    return 0;
}
