//SERVICE GSM
#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;
class obiectePrimite
{
private:
    const int cod; //codul clientului
    bool fix; //reparat sau nu
    char N;//Initiala client
    char* model;//modelul device-ului
    float cost;//costul rep
    /*int* piese;// numarul de piese defecte*/
    double profit;// profitul obtinut din reparatie
    std::string numeAngajat;//cine il repara

    float* costPiese;// costul pieselor
    std::string* numePieseStricate;//numele pieselor stricate
    int *codPiese;//codul pieselor
    int nrPiese;//nr de piese

public:
    static int nrObiectePrimite;//cate obiecte au intrat in Service
///CONSTRUCTOR CU TOTI PARAMETRII
    obiectePrimite(bool fix, char N, char* model, double profit, std::string numeAngajat, float* costPiese, int*codPiese, std::string* numePieseStricate, int nrPiese):cod(nrObiectePrimite++)
    {
        this->fix=fix;
        this->N=N;
        this->profit= profit;
        this->numeAngajat=numeAngajat;
        this->nrPiese= nrPiese;

        this->costPiese= new float[nrPiese];
        for(int i=0; i<nrPiese; i++)
            this->costPiese[i] = costPiese[i];

        this->codPiese=new int[nrPiese];
        for(int i=0; i<nrPiese; i++)
            this->codPiese[i]=codPiese[i];


        this->numePieseStricate= new std::string[nrPiese];
        for(int i=0; i<nrPiese; i++)
            this->numePieseStricate[i]=numePieseStricate[i];


        this->model = new char[strlen(model)+1];
        strcpy(this->model,model);

    }
/// CONSTRUCTOR CU 3 PARAMETRII
    obiectePrimite(bool fix,char* model,std::string numeAngajat):cod(nrObiectePrimite++)
    {
        this->fix=fix;
        this->numeAngajat=numeAngajat;
        this->model = new char[strlen(model)+1];
        strcpy(this->model,model);

        N=NULL;
        profit=0;
        costPiese=NULL;
        codPiese=NULL;
        numePieseStricate=NULL;
        nrPiese=0;
    }

/// CONSTRUCTOR
    obiectePrimite():cod(nrObiectePrimite++)
    {
        fix = false;
        numeAngajat="";
        N = 'q';
        model = NULL;
        cost = 0;
        profit = 0;
        costPiese = NULL;
        codPiese = NULL;
        numePieseStricate= NULL;
        nrPiese = 0;

    }
///DESTRUCTOR
    ~obiectePrimite()
    {
        if(this->model!=NULL)
            delete [] this->model;
        if(this->costPiese!=NULL)
            delete[]this->costPiese;
        if(this->codPiese!=NULL)
            delete[] this->codPiese;
        if(this->numePieseStricate!=NULL)
            delete[] this->numePieseStricate;
    }
///COPY-CONSTRUCTOR
    obiectePrimite(const obiectePrimite& ob):cod(nrObiectePrimite++)
    {
        this->fix=ob.fix;
        this->N=ob.N;
        this->profit= ob.profit;
        this->numeAngajat=ob.numeAngajat;
        this->nrPiese= ob.nrPiese;

        this->costPiese= new float[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
        {
            this->costPiese[i] = ob.costPiese[i];
        }
        this->codPiese=new int[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
            this->codPiese[i]=ob.codPiese[i];

        this->numePieseStricate= new std::string[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
        {
            this->numePieseStricate[i]=ob.numePieseStricate[i];
        }

        this->model = new char[strlen(ob.model)+1];
        strcpy(this->model,ob.model);

    }
///OPERATOR = bool fix, char N, char* model, double profit, std::string numeAngajat, float* costPiese, int*codPiese, std::string* numePieseStricate, int nrPiese
    obiectePrimite &operator =(const obiectePrimite& ob)
    {
        if(this!=&ob)
        {
            if(this->model!=NULL)
                delete [] this->model;
            if(this->costPiese!=NULL)
                delete[]this->costPiese;
            if(this->codPiese!=NULL)
                delete[] this->codPiese;
            if(this->numePieseStricate!=NULL)
                delete[] this->numePieseStricate;

            this->fix=ob.fix;
            this->N=ob.N;
            this->profit= ob.profit;
            this->numeAngajat=ob.numeAngajat;
            this->nrPiese= ob.nrPiese;

            this->costPiese= new float[ob.nrPiese];

            for(int i=0; i<ob.nrPiese; i++)
            {
                this->costPiese[i] = ob.costPiese[i];
            }

            this->codPiese=new int[ob.nrPiese];
            for(int i=0; i<ob.nrPiese; i++)
                this->codPiese[i]=ob.codPiese[i];

            this->numePieseStricate= new std::string[ob.nrPiese];
            for(int i=0; i<ob.nrPiese; i++)
            {
                this->numePieseStricate[i]=ob.numePieseStricate[i];
            }
            if(ob.model!=NULL)
            {
                this->model = new char[strlen(ob.model)+1];
                strcpy(this->model,ob.model);
            }
            else
                this->model=NULL;
        }
        return *this;
    }

    /// OSTREAM
    friend ostream& operator<<(ostream& out, const obiectePrimite& ob);
    ///ISTREAM
    friend istream& operator>>(istream& in, obiectePrimite& ob);
    /// OPERATOR ++ SI --
    const obiectePrimite operator++(int)
    {
        obiectePrimite aux(*this);
        this->profit+=100;

        return aux;
    }
    const obiectePrimite& operator++()
    {
        this->profit+=100;
        return *this;

    }
    //bool fix, char N, char* model, double profit, std::string numeAngajat, float* costPiese, std::string* numePieseStricate, int nrPiese
    ///OPERATOR == < >
    bool operator ==(const obiectePrimite& ob)
    {
        if(strcmp(this->model, ob.model )==0) return true;
        return false;
    }
    bool operator <(const obiectePrimite& ob)
    {
        if(this->profit<ob.profit)return true;
        return false;
    }
    bool operator>(const obiectePrimite&ob)
    {
        if(this->profit>ob.profit )return true;
        return false;
    }
    ///OPERATOR +
    double operator+(obiectePrimite ob)
    {
        //if(this->fix == false or ob.fix == false) ob.fix=false;

        //ob.profit+=this->profit;
        /*
        this->nrPiese+=ob.nrPiese;
        if(this->nrPiese!=NULL)
        {
            string* str=new string[3];
            float* aux =new float[ob.nrPiese];
            int *auxi=new int[ob.nrPiese];


            for(int i=0; i<ob.nrPiese; i++)
            {
                aux[i]=ob.costPiese[i];
                auxi[i]=ob.codPiese[i];
                str[i] = ob.numePieseStricate[i];
            }

            delete[] ob.costPiese;
            delete[] ob.codPiese;
            delete[] ob.numePieseStricate;

            int p1 = ob.nrPiese;
            ob.nrPiese+=this->nrPiese;
            ob.costPiese = new float[ob.nrPiese];
            ob.codPiese = new int[ob.nrPiese];
            ob.numePieseStricate= new string[ob.nrPiese];
            for(int i=0; i<p1; i++)
            {
                ob.costPiese[i]=aux[i];
                ob.codPiese[i]=auxi[i];
                ob.numePieseStricate[i]=str[i];
            }
            for(int i=p1; i<ob.nrPiese; i++)
            {
                ob.costPiese[i]=this->costPiese[i-p1];
                ob.codPiese[i]=this->codPiese[i-p1];
                ob.numePieseStricate[i]=this->numePieseStricate[i-p1];
            }
        }
        return ob;*/
        return this->profit+ob.profit;
    }
    ///OPERATOR *SI []
    obiectePrimite operator*(obiectePrimite ob)
    {
        ob.profit+=this->profit;
        return ob;
    }
    string operator[](int i)
    {
        string ret="Nu exista aceasta piesa";
        if(i>0 && i<=this->nrPiese-1)
            return this->numePieseStricate[i];
        else return ret;
    }
    ///OPERATOR CAST EXPLICIT
    explicit operator int()
    {
        return (int)this->cod;
    }
    ///FUNCTIONALITATE:
    void afisareData();

    bool get_fix();
    void set_fix(bool fix);
    char get_N();
    void set_N(char N);
    char* get_model();
    void set_model(char*model);
    double get_profit();
    void set_profit(double profit);
    std::string get_numeAngajat();
    void set_numeAngajat(std::string numeAngajat);
    float* get_costPiese();
    void set_costPiese(float* costPiese,int nrPiese);
    int* get_codPiese();
    void set_codPiese(int* codPiese,int nrPiese);
    std::string* get_numePieseStricate();
    void set_numePieseStricate(std::string* numePieseStricate,int nrPiese);
    int get_nrPise();
    void set_nrPiese(int nrPiese);
};
    bool obiectePrimite::get_fix(){return fix;}
    void obiectePrimite::set_fix(bool fix){this->fix=fix;}
    char obiectePrimite::get_N(){return N;}
    void obiectePrimite::set_N(char N){this->N=N;}
    char* obiectePrimite::get_model(){return model;}
    void obiectePrimite::set_model(char*model){if(this->model!=NULL)delete[] this->model;this->model=new char[strlen(model)+1];strcpy(this->model,model);}
    double obiectePrimite::get_profit(){return profit;}
    void obiectePrimite::set_profit(double profit){this->profit=profit;}
    std::string obiectePrimite::get_numeAngajat(){return numeAngajat;}
    void obiectePrimite::set_numeAngajat(std::string numeAngajat){this->numeAngajat=numeAngajat;}
    float* obiectePrimite::get_costPiese(){return costPiese;}
    void obiectePrimite::set_costPiese(float* costPiese,int nrPiese)
    {
        if(this->costPiese!=NULL)
            delete[]this->costPiese;
        this->costPiese=new float[nrPiese];
        for(int i=0; i<nrPiese; i++)
        {
            this->costPiese[i] = costPiese[i];
        }
    }
    int* obiectePrimite::get_codPiese(){ cout<<this->codPiese<<"\n"; return this->codPiese;}
    void obiectePrimite::set_codPiese(int* codPiese,int nrPiese)
    {
        if(this->codPiese!=NULL)
            delete[]this->codPiese;
        this->codPiese=new int[nrPiese];
        for(int i=0; i<nrPiese; i++)
        {
            this->codPiese[i] = codPiese[i];
        }
    }
    std::string* obiectePrimite::get_numePieseStricate(){return numePieseStricate;}
    void obiectePrimite::set_numePieseStricate(std::string* numePieseStricate,int nrPiese)
    {
        if(this->numePieseStricate!=NULL)
            delete[] numePieseStricate;
        this->numePieseStricate= new std::string[nrPiese];
        for(int i=0; i<nrPiese; i++)
        {
            this->numePieseStricate[i]=numePieseStricate[i];
        }
    }
int obiectePrimite::nrObiectePrimite = 0;
///OSTREAM

ostream& operator<<(ostream& out, const obiectePrimite& ob)
{
    out<<"Stare: ";
    if(ob.fix == false) out<<"stricat";
    else out<<"reparat";

    out<<"\nInitiala client: ";
    if(ob.N!=NULL)out<<ob.N;
    out<<"\nModel device: ";
    if(ob.model!=NULL)out<<ob.model;
    out<<"\nProfit: ";
    if(ob.profit>0)out<<ob.profit;

    out<<"\nNume angajat: "<<ob.numeAngajat;
    if(ob.nrPiese>0)
    {
        out<<"\nCost piese: ";
        for(int i=0; i<ob.nrPiese; i++)
            out<<i+1<<"-"<<ob.costPiese[i]<<"\n";
        out<<"Cod piese: "<<"\n";
        for(int i=0; i<ob.nrPiese; i++)
            out<<i+1<<"-"<<ob.codPiese[i]<<"\n";
        out<<"Nume piese stricate: "<<"\n";
        for(int i=0; i<ob.nrPiese; i++)
            out<<i+1<<"-"<<ob.numePieseStricate[i]<<"\n";
    }
    return out;
}
//:: sn deferentiere
///ISTREAM
istream& operator>>(istream& in, obiectePrimite& ob)
{
    ///bool fix, char N, char* model, double profit, std::string numeAngajat, float* costPiese, std::string* numePieseStricate, int nrPiese
    char aux[100];
    cout<<"Initiala client: "<<"\n";
    in>>ob.N;
    cout<<"Model device: "<<"\n";
    in>>aux;
    if(ob.model!=NULL)delete[] ob.model;
    ob.model= new char[strlen(aux)+1];
    strcpy(ob.model,aux);
    cout<<"Profit: "<<"\n";
    in>>ob.profit;
    cout<<"Nume angajat: "<<"\n";
    in>>ob.numeAngajat;
    cout<<"Numar piese stricate\n ";
    in>>ob.nrPiese;
    if(ob.nrPiese<1)cout<<"Obiectul nu este stricat";
    else
    {
        cout<<"Cost piese: "<<"\n";
        if(ob.costPiese!=NULL)
            delete[] ob.costPiese;
        ob.costPiese = new float[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
            in>>ob.costPiese[i];
        cout<<"Cod piese: "<<"\n";
        if(ob.codPiese!=NULL)
            delete[] ob.codPiese;
        ob.codPiese = new int[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
            in>>ob.codPiese[i];

        cout<<"Nume piese stricate: "<<"\n";
        if(ob.numePieseStricate!=NULL)
            delete[] ob.numePieseStricate;
        ob.numePieseStricate= new std::string[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
            in>>ob.numePieseStricate[i];
    }
    return in;


}
///FUNCTIONALITATE
void obiectePrimite::afisareData()
{
    float s=0;
    for(int i=0;i<this->nrPiese;i++)
        s+=this->costPiese[i];
    cout<<"Reparatia produsului costa: "<<s*1.5<<" lei si poate dura "<<this->nrPiese<<" ore\n";
}
class angajati {
protected:
    char *Nume;
    char *Prenume;
    const int idAngajat;
    double salariu;

    float *istoricSalariu;
    int istoricLuni;

    string *proiecte;
    int nrProiecte;
///CONSTRUCTORI
public:
    static int nr;
    angajati():idAngajat(nr++)
    {
        Nume=NULL;
        Prenume=NULL;
        salariu=0;
        istoricSalariu=NULL;
        istoricLuni=0;
        proiecte=NULL;
        nrProiecte=0;
    }
    angajati(char *Nume, char*Prenume, double salariu, float *istoricSalariu, int istoricLuni,string * proiecte, int nrProiecte):idAngajat(nr++)
    {
        this->salariu=salariu;
        this->istoricLuni=istoricLuni;
        this->nrProiecte=nrProiecte;
        this->Nume = new char[strlen(Nume)+1];
        strcpy(this->Nume,Nume);
        this->Prenume= new char[strlen(Prenume)+1];
        strcpy(this->Prenume,Prenume);
        this->istoricSalariu=new float[istoricLuni];
        for(int i = 0;i<istoricLuni;i++)
            this->istoricSalariu[i]=istoricSalariu[i];
        this->proiecte= new string[nrProiecte];
        for(int i = 0;i<nrProiecte;i++)
            this->proiecte[i]=proiecte[i];
    }
    angajati(char *Nume, char*Prenume, double salariu):idAngajat(nr++)
    {
        this->salariu=salariu;
        this->Nume = new char[strlen(Nume)+1];
        strcpy(this->Nume,Nume);
        this->Prenume= new char[strlen(Prenume)+1];
        strcpy(this->Prenume,Prenume);
        istoricSalariu=NULL;
        istoricLuni=0;
        proiecte=NULL;
        nrProiecte=0;
    }
///DESTRUCTOR
    ~angajati()
    {
        if(Nume!=NULL)
            delete[] Nume;
        if(Prenume!=NULL)
            delete[] Prenume;
        if(proiecte!=NULL)
            delete[] proiecte;
        if(istoricSalariu!=NULL)
            delete[] istoricSalariu;
    }
///COPY
    angajati(const angajati& ob):idAngajat(nr++)
    {
        this->salariu=ob.salariu;
        this->istoricLuni=ob.istoricLuni;
        this->nrProiecte=ob.nrProiecte;
        this->Nume = new char[strlen(ob.Nume)+1];
        strcpy(this->Nume,ob.Nume);
        this->Prenume= new char[strlen(ob.Prenume)+1];
        strcpy(this->Prenume,ob.Prenume);
        this->istoricSalariu=new float[ob.istoricLuni];
        for(int i = 0;i<ob.istoricLuni;i++)
            this->istoricSalariu[i]=ob.istoricSalariu[i];
        this->proiecte= new string[ob.nrProiecte];
        for(int i = 0;i<ob.nrProiecte;i++)
            this->proiecte[i]=ob.proiecte[i];

    }
///= char *Nume, char*Prenume, double salariu, float *istoricSalariu, int istoricLuni,string * proiecte, int nrProiecte
    angajati &operator = (const angajati& ob)
    {

        if(this!=&ob)
        {
            if(this->Nume!=NULL)
                delete[] this->Nume;
            if(this->Prenume!=NULL)
                delete[] this->Prenume;

            if(this->proiecte!=NULL)
                delete[] this->proiecte;

            if(this->istoricSalariu!=NULL)
                delete[] this->istoricSalariu;

            this->salariu=ob.salariu;
            this->istoricLuni=ob.istoricLuni;
            this->nrProiecte=ob.nrProiecte;

            if(ob.Nume!=NULL)
            {
                this->Nume = new char[strlen(ob.Nume)+1];
                strcpy(this->Nume,ob.Nume);
            }
            else this->Nume = NULL;
            if(ob.Prenume!=NULL){
                this->Prenume= new char[strlen(ob.Prenume)+1];
                strcpy(this->Prenume,ob.Prenume);
            }
            else this->Prenume = NULL;
            if(ob.istoricLuni>0)
            {
                this->istoricSalariu=new float[ob.istoricLuni];
                for(int i = 0; i<ob.istoricLuni; i++)
                    this->istoricSalariu[i]=ob.istoricSalariu[i];
            }
            if(ob.nrProiecte>0)
            {
                this->proiecte= new string[nrProiecte];
                for(int i = 0; i<nrProiecte; i++)
                    this->proiecte[i]=proiecte[i];
            }
        }
        return *this;
    }
    ///METODE
    void set_Nume(char *Nume);
    char* get_Nume();
    void set_Prenume(char *Prenume);
    char* get_Prenume();
    void set_salariu(double salariu);
    double get_salariu();
    void set_istoricSalariu(float *istoricSalariu, int istoricLuni);
    float *get_istoricSalariu();
    void set_istoricLuni(int istoricLuni);
    int get_istoricLuni();
    void set_proiecte(string *proiecte,int nrProiecte);
    string * get_proiecte();
    void set_nrProiecte(int nrProiecte);
    int get_nrProiecte();
    ///OSTREAM
    friend ostream& operator<<(ostream& out, const angajati& ob);
    ///ISTREAM
    friend istream& operator>>(istream& in, angajati& ob);
    ///OPERATOR ++
    const angajati operator++(int)
    {
        angajati aux(*this);
        this->salariu+=100;

        return aux;
    }
    const angajati& operator++()
    {
        this->salariu +=100;
        return *this;

    }
    ///[]
    string operator[](int i)
    {
        string ret = "Nu exista acest proiect";
        if(i>0 and i<this->nrProiecte-1)return this->proiecte[i];
        else return ret;
    }
    double operator*(angajati ob)
    {
        return ob.salariu+this->salariu;
    }
    ///char *Nume, char*Prenume, double salariu, float *istoricSalariu, int istoricLuni,string * proiecte, int nrProiecte
    int operator-(angajati ob)
    {
        return this->nrProiecte-ob.nrProiecte;
        //string* aux= new string[];
        /*int n=this->nrProiecte;
        int k=0;
        for(int i=0; i<this->nrProiecte; i++)
            for (int j=0; j<this->nrProiecte; j++)
                if(ob.proiecte[j] == this->proiecte[i])
                    n--;
        string* aux= new string[n];
        for(int i=0; i<this->nrProiecte; i++)
            for (int j=0; j<this->nrProiecte; j++)
                if(j==ob.nrProiecte-1 && (ob.proiecte[j] != this->proiecte[i]))
                    aux[k++] = this->proiecte[i];

        return aux;*/
    }
    ///CAST
    explicit operator int()
    {
        return (int)this->idAngajat;
    }
    bool operator==(angajati& ob)
    {
        if(strcmp(this->Nume,ob.Nume)==0 && strcmp(this->Prenume,ob.Prenume)==0 && this->salariu==ob.salariu) return true;
        else return false;
    }
    bool operator>=(angajati& ob)
    {
        if(this->nrProiecte>=ob.nrProiecte)return true;
        else return false;
    }
    ///FUNCTIONALITATE: (char *Nume, char*Prenume, double salariu, float *istoricSalariu, int istoricLuni,string * proiecte, int nrProiecte):idAngajat(nr++)
    void afisareS();
    virtual ostream& Afisare(ostream& out)const
    {
        out<<"Nume si prenume angajat: ";
        if(this->Nume!=NULL)out<<this->Nume<<" ";
        if(this->Prenume!=NULL)out<<this->Prenume;
        out<<"\nID: "<<this->idAngajat;
        out<<"\nSalariu lunar actual: "<<this->salariu<<" lei";
        if(this->istoricLuni>1)
        {
            out<<"Salariul pe ultimele "<<this->istoricLuni<<" luni: ";
            for(int i=0; i<this->istoricLuni; i++)
                out<<this->istoricSalariu[i]<<" ";
            out<<"\n";
        }
        if(this->nrProiecte>1)
        {
            out<<"Denumirea ultimelor "<<this->nrProiecte<<" proiecte:"<<"\n";
            for(int i=0; i<this->nrProiecte; i++)
                out<<i<<"."<<this->proiecte[i]<<"\n";
        }
        return out;
    }
    virtual istream& Citire(istream& in)
    {
        char aux[100];
    cout<<"Nume angajat: ";
    in>>aux;
    if(this->Nume!=NULL) delete[] this->Nume;
    this->Nume = new char[strlen(aux)+1];
    strcpy(this->Nume,aux);
    cout<<"\n"<<"Prenume angajat: ";
    if(this->Prenume!=NULL) delete[] this->Prenume;
    this->Prenume = new char[strlen(aux)+1];
    strcpy(this->Prenume,aux);
    in>>this->Prenume;
    cout<<"\n"<<"Salariu actual: ";
    in>>this->salariu;
    cout<<"Cate luni a muncit ?";
    in>>this->istoricLuni;
    if(this->istoricLuni!=0)
    {
        if(this->istoricSalariu!=NULL)delete[] this->istoricSalariu;
        this->istoricSalariu = new float[this->istoricLuni];
        cout<<"\n";
        cout<<"Introduceti salariul pentru cele "<<this->istoricLuni<<" luni: ";
        for(int i=0;i<this->istoricLuni;i++)
            in>>this->istoricSalariu[i];
        cout<<"\n";
    }
    cout<<"La cate proiecte a participat ? ";
    in>>this->nrProiecte;
    if(this->nrProiecte!=0)
    {
        if(this->proiecte!=NULL) delete[] this->proiecte;
        this->proiecte = new string[this->nrProiecte];
        cout<<"\n";
        cout<<"Introduceti denumirea celor "<<this->nrProiecte<<" proiecte: \n";
        for(int i=0;i<this->nrProiecte;i++){
            cout<<i+1<<"-";
            in>>this->proiecte[i];
        }
        cout<<"\n";
    }
    }

};
void angajati::set_Nume(char *Nume)
{
    if(this->Nume!=NULL)delete[] this->Nume;
    this->Nume=new char[strlen(Nume)+1];
    strcpy(this->Nume,Nume);
}
char* angajati::get_Nume(){return this->Nume;}
void angajati::set_Prenume(char *Prenume)
{
    if(this->Prenume!=NULL)delete[] this->Prenume;
    this->Prenume=new char[strlen(Prenume)+1];
    strcpy(this->Prenume,Prenume);
}
char*angajati:: get_Prenume(){return this->Prenume;}
void angajati:: set_salariu(double salariu){this->salariu=salariu;}
double angajati::get_salariu(){return this->salariu;}
void angajati::set_istoricSalariu(float *istoricSalariu, int istoricLuni)
{
    if(this->istoricSalariu!=NULL)delete[] this->istoricSalariu;
    this->istoricLuni=istoricLuni;
    this->istoricSalariu=new float[istoricLuni];

    for(int i = 0; i<istoricLuni; i++)
        this->istoricSalariu[i]=istoricSalariu[i];

}
float* angajati::get_istoricSalariu(){return this->istoricSalariu;}
void angajati::set_istoricLuni(int istoricLuni){this->istoricLuni=istoricLuni;}
int angajati::get_istoricLuni(){return istoricLuni;}
void angajati::set_proiecte(string *proiecte,int nrProiecte)
{
    if(this->proiecte==NULL) delete[] this->proiecte;
    this->nrProiecte=nrProiecte;
    this->proiecte= new string[nrProiecte];
        for(int i = 0;i<nrProiecte;i++)
            this->proiecte[i]=proiecte[i];
}
void angajati:: set_nrProiecte(int nrProiecte){this->nrProiecte= nrProiecte;}
int angajati:: get_nrProiecte(){return nrProiecte;}


ostream& operator<<(ostream& out, const angajati& ob)
{
    return ob.Afisare(out);
}
istream& operator>>(istream& in, angajati& ob)
{
    return ob.Citire(in);
}
int angajati::nr = 0;
void angajati:: afisareS()
{
    if(this->istoricLuni>=24)
    {
        double s=0;
        int l=this->nrProiecte;
        for(int i = 0;i<l;i++)
              s+=this->istoricSalariu[i];
        s=(double)s/l;
        cout<<"Angajatul este senior \n";
        cout<<"Media salariului este "<<s<<" lei\n";
    }
    else if(this->istoricLuni<24 && this->istoricLuni>3)cout<<"Angajatul este junior\n";
    else cout<<"Angajatul este novice\n";
}
class produse {
    private:
    string nume;//nume produs
    double pret;//pret
    int conditie;//conditie device (5=excelenta,4=foarte buna,3=buna,2=medie,1=acceptabila,0=defect)
    string descriere;//scurta descriere
    string *pieseInlocuite;
    int nrPiese;
    public:
    produse()
    {
        nume = "Device fara nume";
        pret = 0;
        conditie = -1;
        descriere= "Fara descriere";
        pieseInlocuite=NULL;
        nrPiese=0;
    }
    produse(string nume,double pret,int conditie,string descriere,string *pieseInlocuite,int nrPiese)
    {
        this->nume=nume;
        this->pret=pret;
        this->conditie=conditie;
        this->descriere=descriere;
        this->nrPiese=nrPiese;
        this->pieseInlocuite= new string[nrPiese];
        for(int i=0; i<nrPiese; i++)
            this->pieseInlocuite[i]=pieseInlocuite[i];
    }
    produse(string nume,double pret,int conditie,string descriere)
    {
        this->nume=nume;
        this->pret=pret;
        this->conditie=conditie;
        this->descriere=descriere;
        this->nrPiese=0;
        this->pieseInlocuite=NULL;
    }
    ~produse()
    {
        if(pieseInlocuite!=NULL)delete[] pieseInlocuite;
    }

    produse(const produse&ob)
    {
        this->nume=ob.nume;
        this->pret=ob.pret;
        this->conditie=ob.conditie;
        this->descriere=ob.descriere;
        this->nrPiese=ob.nrPiese;
        this->pieseInlocuite= new string[ob.nrPiese];
        for(int i=0; i<ob.nrPiese; i++)
            this->pieseInlocuite[i]=ob.pieseInlocuite[i];
    }
    produse &operator = (const produse&ob)
    {
        if(this!=&ob)
        {
            this->nume=ob.nume;
            this->pret=ob.pret;
            this->conditie=ob.conditie;
            this->descriere=ob.descriere;
            this->nrPiese=ob.nrPiese;
            if(pieseInlocuite!=NULL)delete[] pieseInlocuite;
            this->pieseInlocuite= new string[ob.nrPiese];
            for(int i=0; i<ob.nrPiese; i++)
                this->pieseInlocuite[i]=ob.pieseInlocuite[i];
        }
        return *this;
    }
    string get_nume();
    double get_pret();
    int get_conditie();
    string get_descriere();
    void set_nume(string nume);
    void set_pret (double pret);
    void set_conditie(int conditie);
    void set_descriere(string descriere);
    const produse operator++(int)
    {
        produse aux(*this);
        this->pret+=100;

        return aux;
    }
    const produse& operator++()
    {
        this->pret +=100;
        return *this;
    }
    friend istream& operator>>(istream& in, produse& ob);
    friend ostream& operator<<(ostream& out, const produse& ob);
    string operator[](int i)
    {
        string ret ="Piesa nu exista";
        if(i>0 && i<this->nrPiese)return this->pieseInlocuite[i];
        else return ret;
    }
    ///string nume,double pret,int conditie,string descriere,string *pieseInlocuite,int nrPiese
    produse& operator+(produse&ob)
    {
        produse aux;
        aux.nume = this->nume+ob.nume;
        aux.conditie =(this->conditie+ob.conditie)/2;
        aux.pret = this->pret+ob.pret;
        aux.descriere=this->descriere+ob.descriere;

        aux.nrPiese=this->nrPiese+ob.nrPiese;
        for(int i=0;i<this->nrPiese;i++)
            aux.pieseInlocuite[i]=this->pieseInlocuite[i];

        for(int i=0;i<ob.nrPiese;i++)
            aux.pieseInlocuite[this->nrPiese+i]=this->pieseInlocuite[i];
        return aux;
    }
    double operator*(produse&ob)
    {
        return this->pret+ob.pret;
    }
    explicit operator int()
    {
        return (int)this->nrPiese;
    }
    bool operator ==(const produse& ob)
    {
        if(this->nume == ob.nume) return true;
        return false;
    }
    bool operator <(const produse& ob)
    {
        if(this->pret<ob.pret)return true;
        return false;
    }
    bool operator>(const produse&ob)
    {
        if(this->pret>ob.pret )return true;
        return false;
    }
    ///FUNCTIONALITATE:
    void calc(double cost);
};
string produse:: get_nume(){return nume;}
double produse:: get_pret(){return pret;}
int produse:: get_conditie(){return conditie;}
string produse:: get_descriere(){return descriere;}
void produse::set_nume(string nume){this->nume=nume;}
void produse::set_pret (double pret){this->pret=pret;}
void produse::set_conditie(int conditie){this->conditie=conditie;}
void produse::set_descriere(string descriere){this->descriere=descriere;}

istream& operator>>(istream& in, produse& ob)
{
    cout<<"Introduceti denumirea produsului: ";
    in>>ob.nume;
    cout<<"Care este pretul acestuia: ";
    in>>ob.pret;
    cout<<"In ce conditie se afla: 0,1,2,3,4,5 ?";
    in>>ob.conditie;
    cout<<"O scurta descriere:\n";
    in>>ob.descriere;
    cout<<"Cate piese au fost inlocuite? ";
    in>>ob.nrPiese;
    if(ob.nrPiese>0)
    {
        ob.pieseInlocuite = new string[ob.nrPiese];
        cout<<"Ce piese au fost inlocuite?\n";
        for(int i=0;i<ob.nrPiese;i++)
            in>>ob.pieseInlocuite[i];
    }
}
ostream& operator<<(ostream& out, const produse& ob)
{
    out<<"Denumire produs: "<<ob.nume;
    out<<"\nPret: "<<ob.pret;
    out<<"\nConditie: ";
    int n=ob.conditie;
    switch(n)
    {
        case 0:out<<"device defect";break;
        case 1:out<<"acceptabila";break;
        case 2:out<<"medie";break;
        case 3:out<<"buna";break;
        case 4:out<<"foarte buna";break;
        case 5:out<<"excelenta";break;
    }
    out<<"\nDescriere: ";
    out<<ob.descriere;
    if(ob.nrPiese>0)
    {
        out<<"\nDevice-ul are "<<ob.nrPiese<<" piese schimbate\n";
        for(int i=0;i<ob.nrPiese;i++)
            cout<<i+1<<"."<<ob.pieseInlocuite[i]<<"\n";
    }
}
void produse::calc(double cost)
{
    int r= this->pret-cost;
    if(r>10)
    {

        double red = rand() % r + 10;

        cout<<"O posibila reducere ar fi: "<<red - (10/this->conditie)<<" lei\n";
    }
    else cout<<"Nu se pot face reduceri\n";
}
class client {
    protected:
    string nume;//denumire luna curenta
    string prenume;//
    string adresaDeEmail;
    string adresa;
    int varsta;
    char* produs;
    string defect;//defecetul produsului adus
public:
    client()
    {
        nume="";
        prenume="";
        adresaDeEmail="";
        adresa="";
        varsta=0;
        produs=NULL;
        defect="";
    }
    client(string nume,string prenume,string adresaDeEmail,string adresa, int varsta, char*produs, string defect)
    {
        this->nume=nume;
        this->prenume=prenume;
        this->adresaDeEmail=adresaDeEmail;
        this->adresa=adresa;
        this->varsta=varsta;
        this->produs=new char[strlen(produs)+1];
        strcpy(this->produs,produs);
        this->defect=defect;
    }
    client(string nume,string prenume,string adresaDeEmail,string adresa)
    {
        this->nume=nume;
        this->prenume=prenume;
        this->adresaDeEmail=adresaDeEmail;
        this->adresa=adresa;
        this->varsta=0;
        this->produs=NULL;
        this->defect="";
    }
    client(int n)
    {
        this->varsta=n;
    }
    ~client()
    {
        if(produs!=NULL)delete[] produs;
    }
    client(const client& ob)
    {
        this->nume=ob.nume;
        this->prenume=ob.prenume;
        this->adresaDeEmail=ob.adresaDeEmail;
        this->adresa=ob.adresa;
        this->varsta=ob.varsta;

        if(ob.produs==NULL)this->produs=NULL;
        else
        {
            this->produs=new char[strlen(ob.produs)+1];
            strcpy(this->produs,ob.produs);
        }
        this->defect=ob.defect;
    }
    client& operator =(const client& ob)
    {
        if(this!=&ob)
        {
            if(this->produs!=NULL)delete[] this->produs;
            this->nume=ob.nume;
            this->prenume=ob.prenume;
            this->adresaDeEmail=ob.adresaDeEmail;
            this->adresa=ob.adresa;
            this->varsta=ob.varsta;

            if(ob.produs!=NULL)
            {
                this->produs=new char[strlen(ob.produs)+1];
                strcpy(this->produs,ob.produs);
            }
            else
                this->produs=NULL;
            this->defect=ob.defect;
        }
        return *this;
    }
    const client operator++(int)
    {
        client aux(*this);
        this->varsta++;
        return aux;
    }
    const client& operator++()
    {
        this->varsta++;
        return *this;
    }
    friend ostream& operator<<(ostream& out,const client &ob);
    friend istream& operator>>(istream& in,client &ob);
    string get_nume();
    string get_prenume();
    string get_adresaDeEmail();
    string get_adresa();
    int get_varsta();
    char* get_produs();
    string get_defect();
    void set_nume(string nume);
    void set_prenume(string prenume);
    void set_adresaDeEmail(string adresaDeEmail);
    void set_adresa(string adresa);
    void set_varsta(int varsta);
    void set_produs(char * produs);
    void set_defect(string defect);

    explicit operator string()
    {
        return (string)this->nume;
    }
    char operator[](int i)
    {
        if(i>0 && i<(this->nume).size()) return this->nume[i];
        else return NULL;
    }
///string nume,string prenume,string adresaDeEmail,string adresa, int varsta, char*produs, string defect
    bool operator ==(client &ob)
    {
        if(this->nume==ob.nume&& this->prenume==ob.prenume && this->adresa==ob.adresa)return true;
        else return false;
    }
    bool operator <(client &ob)
    {
        if(this->varsta < ob.varsta)return true;
        else return false;
    }
    bool operator>(client &ob)
    {
        if(this->varsta>ob.varsta)return true;
        return false;
    }
    string operator+(client ob)
    {
        string sp =" ";
        string aux=this->adresaDeEmail+sp+ob.adresaDeEmail;
        return aux;
    }
    float operator/(client ob)
    {
        return ((this->varsta)+ob.varsta)/2;
    }
    ///FUNCTIONALITATE:
    void vars();
    ///afisare
    virtual ostream& Afisare(ostream& out)const
    {
        out<<"Nume client: "<<this->nume;
        out<<"\nPrenume client: "<<this->prenume;
        out<<"\nAdresa de e-mail: "<<this->adresaDeEmail;
        out<<"\nAdresa: "<<this->adresa;
        out<<"\nVarsta: "<<this->varsta;
        out<<"\nModel produs: ";
        if(this->produs!=NULL)out<<this->produs;
        out<<"\nDefectul device-ului: "<<this->defect<<"\n";
        return out;
    }
    virtual istream& Citire(istream& in)
    {
        cout<<"Nume client: ";
        in>>this->nume;
        cout<<"Prenume client: ";
        in>>this->prenume;
        cout<<"Adresa de e-mail: ";
        in>>this->adresaDeEmail;
        cout<<"Adresa clientului: ";
        in>>this->adresa;
        cout<<"Varsta: ";
        in>>this->varsta;
        cout<<"Model produs: ";
        char aux[100];
        in>>aux;
        if(this->produs!=NULL)delete[] this->produs;
        this->produs= new char[strlen(aux)+1];
        strcpy(this->produs,aux);
        cout<<"Ce defect are?: ";
        in>>this->defect;
    }
};
string client::get_nume(){return nume;}
string client::get_prenume(){return prenume;}
string client::get_adresaDeEmail(){return adresaDeEmail;}
string client::get_adresa(){return adresa;}
int client::get_varsta(){return varsta;}
char* client::get_produs(){return produs;}
string client::get_defect(){return defect;}
void client::set_nume(string nume){this->nume=nume;}
void client::set_prenume(string prenume){this->prenume=prenume;}
void client::set_adresaDeEmail(string adresaDeEmail){this->adresaDeEmail=adresaDeEmail;}
void client::set_adresa(string adresa){this->adresa=adresa;}
void client::set_varsta(int varsta){this->varsta=varsta;}
void client::set_produs(char * produs){if(this->produs!=NULL)delete[] this->produs; this->produs= new char[strlen(produs)+1];strcpy(this->produs,produs);}
void client::set_defect(string defect){this->defect=defect;}


ostream& operator<<(ostream& out, const client &ob)
{
    return ob.Afisare(out);
}
istream& operator>>(istream& in, client& ob)
{
    return ob.Citire(in);
}
void client::vars()
{
    if(this->varsta<16)cout<<"Adolesccent";
    else if(this->varsta>16 && this->varsta<30)cout<<"Tanar adult";
    else if(this->varsta>=30 && this->varsta<65)cout<<"Adult";
    else if(this->varsta>=65)cout<<"Varstnic";
    else cout<<"Minor";
}
class client_fidel:public client{
private:
    int discount;
    double valTotala;
    string dataNastere;
public:
    client_fidel():client()
    {
        this->discount=0;
        this->valTotala=0;
        this->dataNastere="";
    }
    client_fidel(int discount,double valTotala, string dataNastere,string nume,string prenume,string adresaDeEmail,string adresa, int varsta, char*produs, string defect):client(nume,prenume,adresaDeEmail,adresa,varsta,produs,defect)
    {
        this->discount=discount;
        this->valTotala=valTotala;
        this->dataNastere=dataNastere;
    }
    client_fidel(int discount, double valTotala,string nume,string prenume,string adresaDeEmail,string adresa):client(nume,prenume,adresaDeEmail,adresa)
    {
        this->discount=discount;
        this->valTotala=valTotala;
        this->dataNastere="";
    }
    ~client_fidel(){}
    client_fidel(const client_fidel & ob):client(ob)
    {
        this->discount=ob.discount;
        this->valTotala=ob.valTotala;
        this->dataNastere=ob.dataNastere;
    }
    client_fidel& operator =(const client_fidel&ob)
    {
        if(this!=&ob)
        {
            client::operator=(ob);
            this->discount=ob.discount;
            this->valTotala=ob.valTotala;
            this->dataNastere=ob.dataNastere;
        }
        return *this;
    }
    ostream& Afisare(ostream& out)const
    {
        client::Afisare(out);
        out<<"Discount: "<<this->discount;
        out<<"\nVal totala: "<<this->valTotala;
        out<<"\nData nasterii: \n"<<this->dataNastere;
        return out;
    }
    istream& Citire(istream& in)
    {
        client::Citire(in);
        cout<<"Discount: ";
        in>>this->discount;
        cout<<"Val totala: ";
        in>>this->valTotala;
        cout<<"Data nasterii: ";
        in>>this->dataNastere;
        return in;
    }
    friend ostream& operator<<(ostream& out,const client_fidel& ob)
    {
        return ob.Afisare(out);
    }

    friend istream& operator>>(istream& in,client_fidel&ob)
    {
        return ob.Citire(in);
    }
    void set_discount(int discount);
    int get_discount();

};
void client_fidel::set_discount(int discount){this->discount=discount;}
int client_fidel::get_discount(){return this->discount;}


class tehnician:public angajati{
private:
    int vechime;
    double bonus;
    double ultimaPrima;
    string ierarhie;
public:
    tehnician():angajati()
    {
        this->vechime=0;
        this->bonus=0;
        this->ultimaPrima=0;
        this->ierarhie="";
    }
    tehnician(int vechime,double bonus, double ultimaPrima, string ierarhie,char *Nume, char*Prenume, double salariu, float *istoricSalariu, int istoricLuni,string * proiecte, int nrProiecte):angajati(Nume, Prenume, salariu, istoricSalariu,istoricLuni,proiecte,nrProiecte)
    {
        this->vechime=vechime;
        this->bonus=bonus;
        this->ultimaPrima=ultimaPrima;
        this->ierarhie=ierarhie;
    }
    tehnician(int vechime,double bonus,char *Nume, char*Prenume, double salariu):angajati(Nume,Prenume,salariu)
    {
        this->vechime=vechime;
        this->bonus=bonus;
        this->ultimaPrima=0;
        this->ierarhie="";
    }
    ~tehnician(){}
    tehnician(const tehnician& ob):angajati(ob)
    {
        this->vechime=ob.vechime;
        this->bonus=ob.bonus;
        this->ultimaPrima=ob.ultimaPrima;
        this->ierarhie=ob.ierarhie;
    }
    tehnician& operator=(const tehnician& ob)
    {
        if(this!=&ob)
        {
            angajati::operator=(ob);
            this->vechime=vechime;
            this->bonus=bonus;
            this->ultimaPrima=ultimaPrima;
            this->ierarhie=ierarhie;
        }
        return *this;
    }
    ostream& Afisare(ostream& out)const
    {
        angajati::Afisare(out);
        out<<"\nVechime: "<<this->vechime;
        out<<"\nBonus: "<<this->bonus;
        out<<"\nultima prima: "<<this->ultimaPrima;
        out<<"\nierarhie: "<<this->ierarhie;
        return out;
    }
    istream& Citire(istream& in)
    {
        angajati::Citire(in);
        cout<<"\nVechime: ";in>>this->vechime;
        cout<<"\nBonus: ";in>>this->bonus;
        cout<<"\nultima prima: ";in>>this->ultimaPrima;
        cout<<"\nierarhie: ";in>>this->ierarhie;
        return in;
    }
    friend ostream& operator<<(ostream& out, const tehnician& ob){
        return ob.Afisare(out);
    }
    friend istream& operator>>(istream& in, tehnician& ob)
    {
        return ob.Citire(in);
    }
    void set_vechime(int i);
    int get_vechime();

};
void tehnician::set_vechime(int i){this->vechime=vechime;}
int tehnician::get_vechime(){return this->vechime;}
///CLASA ABSTRACTA
class distribuitor
{
protected:
    string nume;
    string dataExpirareContract;
public:
    virtual void afisare_promotie()=0;
    distribuitor()
    {
        this->nume="";
        this->dataExpirareContract="";
    }
    distribuitor(string nume, string dataExpirareContract)
    {
        this->nume=nume;
        this->dataExpirareContract=dataExpirareContract;
    }
    distribuitor(string nume)
    {
        this->nume=nume;
        this->dataExpirareContract="";
    }
    distribuitor(distribuitor& ob)
    {
        this->nume=ob.nume;
        this->dataExpirareContract=ob.dataExpirareContract;
    }
    distribuitor& operator=(distribuitor& ob)
    {
        if(this!=&ob)
        {
            this->nume=ob.nume;
            this->dataExpirareContract=ob.dataExpirareContract;
        }
        return *this;
    }
    friend istream& operator>>(istream& in, distribuitor& ob)
    {
        cout<<"\nIntroduceti nume: ";
        in>>ob.nume;
        cout<<"\nIntroduceti data expirarii contractului: ";
        in>>ob.dataExpirareContract;
        return in;
    }
    friend ostream& operator<<(ostream& out,const distribuitor& ob)
    {
        out<<"Nume: "<<ob.nume;
        out<<"\nData expirarii contractului: "<<ob.dataExpirareContract;
        return out;
    }
    ~distribuitor(){};
};
///INTERFATA
class depozit
{
public:
    virtual void afisare_stoc()=0;
    virtual void afisare_marfa()
    {
        cout<<"Nu exista marfa\n";
    }
    virtual void costTotal()
    {
        cout<<"Nu exista cost total\n";
    }
    depozit(){};
    depozit(const depozit& ob){};
    depozit& operator=(depozit&ob)
    {
        return *this;
    }
    friend istream& operator>>(istream& in, depozit& ob){return in;}
    friend ostream& operator<<(ostream& out,const depozit& ob){return out;}
    ~depozit(){};

};
///VIRTUALIZARE
class depozitChitiala:public depozit
{
private:
    int codDepozit;
    string locatie;
    int codFirmaDePaza;
    string marfa;
    int cost;
public:
    depozitChitiala():depozit()
    {
        this->codDepozit=0;
        this->locatie="";
        this->codFirmaDePaza=0;
        this->marfa="";
        this->cost=0;
    }
    depozitChitiala(int codDepozit,string locatie, int codFirmaDePaza,string marfa,int cost):depozit()
    {
        this->codDepozit=codDepozit;
        this->locatie=locatie;
        this->codFirmaDePaza=codFirmaDePaza;
        this->marfa=marfa;
        this->cost=cost;
    }
    depozitChitiala(int codDepozit,string locatie):depozit()
    {
        this->codDepozit=codDepozit;
        this->locatie=locatie;
        this->codFirmaDePaza=0;
        this->marfa="";
        this->cost=0;
    }
    ~depozitChitiala(){}

    depozitChitiala(const depozitChitiala& ob):depozit(ob)
    {
        this->codDepozit=codDepozit;
        this->locatie=locatie;
        this->codFirmaDePaza=codFirmaDePaza;
        this->marfa=marfa;
        this->cost=cost;
    }
    depozitChitiala& operator=(depozitChitiala& ob)
    {
        if(this!=&ob)
        {
            this->codDepozit=codDepozit;
            this->locatie=locatie;
            this->codFirmaDePaza=codFirmaDePaza;
            this->marfa=marfa;
            this->cost=cost;
        }
        return *this;
    }
    friend istream& operator>>(istream& in, depozitChitiala& ob)
    {
        in>>(depozit&)ob;
        cout<<"\nCod depozit: ";
        in>>ob.codDepozit;
        cout<<"\nLocatie: ";
        in>>ob.locatie;
        cout<<"\nCod firma de paza: ";
        in>>ob.codFirmaDePaza;
        cout<<"\nMarfa: ";
        in>>ob.marfa;
        cout<<"\nCost: ";
        in>>ob.cost;
        return in;
    }
    friend ostream& operator<<(ostream& out,const depozitChitiala&ob)
    {
        cout<<"\nCod depozit: ";
        out<<ob.codDepozit;
        cout<<"\nLocatie: ";
        out<<ob.locatie;
        cout<<"\nCod firma de paza: ";
        out<<ob.codFirmaDePaza;
        cout<<"\nMarfa: ";
        out<<ob.marfa;
        cout<<"\nCost: ";
        out<<ob.cost;
        return out;
    }
    void afisare_marfa()
    {
        cout<<this->marfa;
    }
    void afisare_stoc()
    {
        cout<<this->cost;
    }
};
///CLASA HAS A
class persoana_device
{
    private:
    obiectePrimite telefon;
    client cl;
    string data_primire;
    public:
        persoana_device()
        {
            data_primire="";
        }
        persoana_device(string data_primire)
        {
            this->data_primire=data_primire;
        }
        persoana_device(string data_primire, obiectePrimite telefon, client cl)
        {
            this->data_primire=data_primire;
            this->telefon=telefon;
            this->cl=cl;
        }
        persoana_device(const persoana_device& ob)
        {
            this->telefon=ob.telefon;
            this->cl=ob.cl;
            this->data_primire=data_primire;
        }
        persoana_device& operator=(persoana_device& ob)
        {
            if(this!=&ob)
            {
                this->telefon=ob.telefon;
                this->cl=ob.cl;
                this->data_primire=data_primire;
            }
            return *this;
        }

        friend istream& operator>>(istream& in,persoana_device& ob)
        {
             in>>ob.telefon;
             in>>ob.cl;
             cout<<"Data primire: \n";
             in>>ob.data_primire;
             return in;
        }
        friend ostream& operator<<(ostream& out,const persoana_device& ob)
        {
            out<<"Detalii telefon: \n";
            out<<ob.telefon;
            out<<"Detalii client: \n";
            out<<ob.cl;
            out<<"Data primire: "<<ob.data_primire;
            return out;
        }
        ~persoana_device(){}
};
int main()
{
    depozitChitiala ddd;
    cout<<ddd;
    cout<<"\n--------------------------\n";
    string data="22.03.2015";
    char a[]="samsung galaxy a5";
    string num="Ionel Popescu";
    float cs[]= {3.4,5.6,7.8};
    int cd[]={123,445,999};
    string pi[]= {"placa","display","difuzor"};
    obiectePrimite t(false,'g',a,200.8,num,cs,cd,pi,3);
    char md[]="tableta apple";
    client cl("Marian","Ionescu","marinica@yahoo.com","sos.Dudesti Pantelimon",24,md,"display spart");
    persoana_device yy(data,t,cl);
    cout<<yy;

    /*
    angajati *a[10];
    a[0]=new tehnician();
    cin>>*a[0];
    cout<<"\n---------------\n";
    cout<<*a[0];
    cout<<"\n---------------\n";
    client *v[10];
    v[0] = new client_fidel();
    v[1] = new client();
    cin>>*v[0];
    cout<<"\n---------------\n";
    cout<<*v[0];
    cout<<"\n---------------\n";
    string loc="piata matasari 334";
    depozitChitiala depo(334,loc,900);
    depozitChitiala d=depo;
    cout<<d;
    cout<<"\n---------------\n";
    cout<<depo;
    cout<<"\n---------------\n";


    /*
    char nu[]="Ionel";
    char pre[]="Popescu";
    double sal=1200;
    float cs[]= {3.4,5.6,7.8};
    string vec[]={"p1","p2","p3"};
    string vec1[]={"p1","p2"};
    string i="ieri";
    tehnician a(23,44,667,i,nu,pre,sal,cs,3,vec,3);
    tehnician b();
    a=b;
    cout<<b;
    */
    /*
    char a[]="tableta apple";


    client_fidel george(23,445,"23.05.2001","Marian","Ionescu","marinica@yahoo.com","sos.Dudesti Pantelimon",24,a,"display spart(fumat)");
    cout<<george;

    cout<<"\n---------------------------\n";
    client_fidel marcel;

    marcel=george;
    /*
    cout<<marcel;

    ///obiectePrimite
/*
    char a[]="samsung galaxy a5";
    string num="Ionel Popescu";
    float cs[]= {3.4,5.6,7.8};
    int cd[]={123,445,999};
    string pi[]= {"placa","display","difuzor"};
    obiectePrimite t(false,'g',a,200.8,num,cs,cd,pi,3);  ///CONSTRUCTOR CU TOTI PARAMETRII
    cout<<t<<"\n";
    obiectePrimite l=t;                             ///COPY CONSTRUCTOR

    cout<<"---------------------\n";
    l.set_model(t.get_model());                       ///SETTERI SI GETTERI
    l.set_profit(t.get_profit());
    l.set_numeAngajat(t.get_numeAngajat());
    cout<<l;
    cout<<"---------------------\n";
    t.afisareData();                                     ///FUNCTIONALITATE: afiseaza costul si durata posibila a reparatiei
    if(t == l)cout<<"Obiecte asemenea\n";               ///OPERATORUL ==
    cout<<++t;                                          ///OPERATORUL PREINCREMENATARE
    cout<<"---------------------\n";
    cout<<t++;                                          ///OPERATORUL POSTINCREMENTARE
    cout<<"---------------------\n";
    obiectePrimite ob;
    cout<<t;                                            ///FUNCTIA COUT<<
    cout<<"---------------------\n";
    cin>>ob;                                            ///FUNCTIA CIN>>
    cout<<"---------------------\n";
    cout<<ob;
    cout<<"---------------------\n";
    obiectePrimite obb=ob;                              ///OPERATORUL =
    if(obb == ob)cout<<"Obiecte egale\n";
    obb.set_model(t.get_model());                       ///SETTERI SI GETTERI
    obb.set_profit(t.get_profit());
    obb.set_numeAngajat(t.get_numeAngajat());
    cout<<obb;
    cout<<"---------------------\n";
    cout<<obb+t;                                        ///OPERATORUL +
    cout<<"---------------------\n";
    cout<<obb[1];                                       ///OPERATORUL []
    cout<<"---------------------\n";
    cout<<int(obb);                                     ///CAST EXPLICIT
    cout<<"---------------------\n";
    cout<<obb*t;                                        ///OPERATORUL *
    cout<<"---------------------\n";
    ob.afisareData();
    cout<<"---------------------\n";
    if(t>ob) cout<<"samsung";                           ///OPERATORUL >
    else if (t<ob) cout<<"nu e samsung";                ///OPERATORUL <
*/

    ///angajati
    /*
    char nu[]="Ionel";
    char pre[]="Popescu";
    double sal=1200;
    float cs[]= {3.4,5.6,7.8};
    string vec[]={"p1","p2","p3"};
    string vec1[]={"p1","p2"};
    angajati ana(nu,pre,sal,cs,3,vec,3);               ///CONSTRUCTOR CU TOTI PARAMETRII
    angajati nana(nu,pre,sal,cs,3,vec1,2);
    angajati mihai(nu,pre,1450);                        ///CONSTRUCTOR CU 3 PARAMETRII
    angajati ana_copie = ana;                           ///COPY CONSTRUCTOR
    ana.afisareS();///FUNCTIONALITATE: incadreaza angajatul intr-o categorie
    cout<<"---------------------\n";
    cout<<nana;
    if(ana == ana_copie) cout<<"angajati asemenea";       ///OPERATOR ==
    cout<<"---------------------\n";
    cout<< ana-nana;                                    ///OPERATOR -
    cout<<"---------------------\n";
    cout<<ana[1];                                       ///OPERATOR []
    cout<<"---------------------\n";
    cout<<ana *nana;                                    ///OPERATOR *
    cout<<"---------------------\n";
    cout<<++ana;                                        ///PREINCREMENTARE
    cout<<"---------------------\n";
    angajati george;                                    ///CONSTRUCTOR FARA PARAMETRII
    cin>>george;                                        ///FUNCTIA CIN>>
    cout<<"---------------------\n";
    cout<<george;                                       ///FUNCTIA COUT<<
    cout<<"---------------------\n";
    cout<<(int)george;                                  ///EXPLICIT CAST
    cout<<"---------------------\n";
    if(george>=ana) cout<<"GEORGE";                     ///OPERATOR >=
    george.set_Nume(ana.get_Nume());
    george.set_istoricSalariu(ana.get_istoricSalariu(),ana.get_istoricLuni());    /// SETTERI SI GETTERI
    cout<<"---------------------\n";
    cout<<george;

*/
    /*
    ///produse = produsele vandute de GSM (accesorii, device-uri reparate etc)
    srand (time(NULL));                     ///GENERARE RANDOM
    string pi[]={"curea","suport","pedalier"};
    produse p("masina de cusut",1350,3,"Masina de cusut foarte buna recomand",pi,3);///CONSTRUCTOR CU TOTI PARAMETRII
    produse tel("telefon",1100,5,"telefon din Anglia, nu e furat");///CONSTRUCTOR CU 3 PARAMETRII
    tel.calc(1000);
    produse g =tel;
    g.calc(1000);                           ///FUNCTIONALITATE: genereaza o posibila reducere, valoarea introdusa fiind costul de achizitionare
    produse g1 =tel;
    g1.calc(1000);
    produse k;                              ///CONSTRUCTOR FARA PARAMETRII
    g= p;                                   ///OPERATORUL DE ATRIBUIRE
    if(p<tel) cout<<"telefon";              ///OPERATORUL <
    else if(p>tel) cout<<"masina de cusut"; ///OPERATORUL >
    cout<<"---------------------\n";
    produse p_copy=p;                       ///COPY-CONSTRUCTOR
    if(p==p_copy)cout<<"Produse asemenea";   ///OPERATOR ==
    cout<<"---------------------\n";
    cout<<(int)p;                           ///EXPLICIT CAST
    cout<<"---------------------\n";

    cout<<p[1];                             ///OPERATORUL []
    cout<<"---------------------\n";
    cout<<p*tel;                            ///OPERATORUL *
    cout<<"---------------------\n";

    tel.set_conditie(p.get_conditie());     ///SETTER SI GETTER
    tel.set_descriere(p.get_descriere());

    cout<<tel;                              ///FUNCTIA COUT<<
    cout<<"---------------------\n";
    produse ob1;
    cin>>ob1;                               ///FUNCTIA CIN>>
    cout<<"---------------------\n";
    cout<<ob1;
    cout<<"---------------------\n";
    cout<<++ob1;                            ///OPERATORUL ++ PREINCREMENTARE
    cout<<"---------------------\n";
    cout<<ob1++;                            ///OPERATORUL ++ POSTINCREMENTARE
    cout<<"---------------------\n";
    cout<<ob1;
    */
    /*
    ///client
    char a[]="tableta apple";
    client cl("Marian","Ionescu","marinica@yahoo.com","sos.Dudesti Pantelimon",24,a,"display spart"); ///CONSTRUCTORUL CU TOTI PARAMETRII

    client cl1("Ion","Gelu","iongelu@yahoo.com","sos.Colentina nr.45");                               ///CONSTRUCTOR CU 4 PARAMETRII
    cout<<cl1[1];   ///OPERATORUL []
    cout<<cl;
    client cl2=cl1; ///COPY CONSTRUCTOR
    if(cl2==cl1) cout<<"Clienti identici\n"; ///OPERATOR ==
    cout<<"---------------------\n";
    cout<<++cl1;                            ///PREINCREMENTARE
    cout<<"---------------------\n";
    cout<<cl1[1];
    cout<<"---------------------\n";
    cout<<(string)cl1;                      ///CAST EXPLICIT
    cout<<"---------------------\n";
    cout<<cl1+cl;                           ///OPERATORUL +
    cout<<"---------------------\n";
    cout<<cl1/cl;                           ///OPERATORUL /
    cout<<"---------------------\n";
    if(cl1>cl)cout<<"Ion\n";                ///OPERATORUL >
    else if(cl1<cl)cout<<"Marian\n";        ///OPERATORUL <
    cout<<"---------------------\n";
    client cl3;                             ///CONSTRUCTOR FARA PARAMETRII
    cin>>cl3;                               ///FUNCTIA CIN>>
    cout<<"---------------------\n";
    cout<<cl3;                              ///FUNCTIA COUT<<
    cout<<"---------------------\n";
    cl3.vars();                       ///FUNCTIONALITATE - incadreaza clientul intr-o categorie de varsta
*/
    return 0;
}
