#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int rez;
int nr=0;
int v[100];
int i;

char operation[100];
int number;

string aux;
string alegere = "yes";
string title;

class BuildFlow

{

private:

    string text;
    string description;
    string input;


public:

    void Title()
    {

        ofstream o;
        string subtitle;
        cout << "alege titlu:\n";
        getline(cin,title);
        for (char ch : title)
        {
        if (!isalnum(ch))
        {
            throw"S-a gasit caracter invalid in titlu\n";

        }
    }


        cout << "alege subtitlu:\n";
       getline(cin,subtitle);

        o.open(title + ".txt", ios::app);

        o <<"titlu- "<< title << " , " <<"subtitlu- " <<subtitle << endl;

    o.close();
    }

    void Text()

    {

        ofstream o;

        cout<<"alege un text\n";
        getline(cin,aux);
       getline(cin,text);


        o.open(title + ".txt", ios::app);
        o << text << endl;

        o.close();
    }

    void TextINPUT()
    {

        ofstream o;

        cout<<"alege description\n";
         getline(cin,aux);
        getline(cin,description);

        cout<<"alege input\n";

        getline(cin,input);

        o.open(title + ".txt", ios::app);
        o << description << " " << input << endl;

        o.close();
    }

    void numberINPUT()

    {
        int i = 0;

        ofstream o;
        cout<<"alege un numar\n";
        cin >> number;

        o.open(title + ".txt", ios::app);

        o<< number << endl;


    }

    void Calculus()

    {
        ofstream o;
        o.open(title + ".txt", ios::app);
        o<<"se fac atatea opratii cu atatea numere  "<< nr <<" cu o operatia aleasa de aici +/-/*/min/max"<< endl;

        cout<<"alege operatia\n";
        cin >> operation;


        if(strcmp(operation,"+")==0)

        {
            for(i=0; i<nr; i++)

            {
                rez= rez+v[i];
            }
        }

        if(strcmp(operation,"-")==0)

        {
            rez=v[0];

            for(i=1; i<nr; i++)

            {
                rez= rez-v[i];
            }
        }

        if(strcmp(operation,"*")==0)
        {
            rez=v[0];

            for(i=1; i<nr; i++)

            {
                rez= rez * v[i];
            }
        }
        if(strcmp(operation,"min")==0)
        {
            rez=v[0];
            for(i=0; i<nr; i++)
            {
                if(rez>v[i])
                {
                    rez=v[i];
                }

            }
        }
        if(strcmp(operation,"max")==0)
        {
            rez=v[0];
            for(i=0; i<nr; i++)
            {
                if(rez<v[i])
                {
                    rez=v[i];
                }
            }
        }

        o<<"rezultatul opeatiilor este " << rez <<" folosind operatia "<< operation <<endl;



    }
    void Display()
    {
        ifstream f(title + ".txt");

        string linie;

        while (getline(f, linie))
        {
            cout << linie << endl;
        }
    }

    void txtinput()

    {
        ofstream i;
        i.open("fisiertxt.txt", ios::app);
        i<< "Ana are mere\nGigel are pere\n";

        i.close();

        ifstream p("fisiertxt.txt");
        ofstream o;

        o.open(title + ".txt", ios::app);
        string linie;

        while (getline(p, linie))
        {

            o << linie << endl;
        }

    }
    void CSVinput()
    {
        ofstream i;
        i.open("fisiercsv.csv", ios::app);

        i<< "mere,pere,banane\n3lei/kg,5lei/kg,7lei/kg\n";

        i.close();

        ifstream p("fisiercsv.csv");
        ofstream o;

        o.open(title + ".txt", ios::app);
        string linie;

        while (getline(p, linie))
        {

            o << linie << endl;
        }

    }
};

class Afisare : public BuildFlow
{

public:

    Afisare(string mesaj)
    {
        cout<<mesaj;
    }
    ~Afisare()

    {

    }

};

int main()

{
    int error = 0;
     int ceva;
    int n,n1=1;
    char a;
    char c = 'Y';

BuildFlow ex;

try
{

     ex.Title();
}

catch(const char *msg)

{
    cout<< msg;
    ceva =1;
    error++;

}

if(ceva==1)

{
    ex.Title();
}

    cout<<"Afiseaza text cu selectia 1\n";

    cout<<"Afiseaza descriere si input cu selectia 2\n";

    cout<<"Realizeaza operatii cu numere pentru selectia 3 \n";

    cout<<"Afiseaza continul din fisier cu selectia 4\n";

    cout<<"Pune continut din txt cu selectia 5\n";

    cout<<"Pune continut din csv cu selectia 6\n";

    cout<<"Daca doresti sa vezi numarul de erori cu selectia 7\n";

    cout<<"Pune capat pasilor cu orice alt numar\n";


    while(c=='Y')

    {
        cout<<"Introduceti selectia:\n";
         cin >> n;

     switch(n)

     {

    case 1:
     {


    Afisare msj1("Daca doresti sa pui un text apasa y\n");

    cin >> a;

    if(a=='y')
    {
        ex.Text();
    }

    a='n';

     }

    break;

    case 2:
{


    Afisare msj2("Daca doresti sa pui o descriere si un input apasa y\n");

    cin >> a;
    if(a=='y')

    {

        ex.TextINPUT();

    }

    a='n';
}

    break;

    case 3:
        {


    Afisare msj3("Daca doresti sa pui numere pentru operatii tasteaza y\n");

    cin >> a;

    if(a == 'y')

    {


        while (alegere == "yes")
        {

            ex.numberINPUT();

            v[nr]=number;
            nr++;
            cout<<"scrie yes daca vrei sa mai adaugi numere\n";
            cin>>alegere;

        }

        ex.Calculus();

    }

    a='n';

        }

    break;

   case 4:

       {


     Afisare msj4("Daca doresti afisezi continutul din fisier tasteaza y\n");
    cin >> a;
    if(a=='y')

    {
        ex.Display();

    }
    a='n';
       }

  break;

  case 5:

      {
     Afisare msj5("Daca doresti sa adaugi continut in fisier din alt text de tip txt, tasteaza y\n");
    cin >> a;

    if(a=='y')
    {

        ex.txtinput();

    }

    a='n';

     }

break;

case 6:

    {

    Afisare msj6("Daca doresti sa adaugi continut in fisier din alt text de tip csv, tasteaza y\n");
    cin >> a;

    if(a=='y')
    {

        ex.CSVinput();

    }

    a='n';

     }

    break;

case 7:

    {
        Afisare msj7("Daca doresti sa vezi numarul de erori tasteaza y\n");
        cin >> a;

    if(a=='y')
    {
        cout<<error<<endl;
        ofstream m;
       m.open(title+".txt", ios::app);
    }
    a='n';
    }

break;

default:

{

   cout<<"Doriti sa continuati?(Y/N):\n";
        cin>>c;

    }
    break;

    }

    }

    ifstream f(title + ".txt");

     ofstream l;
      l.open("teste.txt", ios::app);

        string linie;

        while (getline(f, linie))
        {
            l << linie <<endl;
        }

    return 0;

}
