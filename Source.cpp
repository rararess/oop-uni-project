#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<list>
#include<vector>

using namespace std;
 
//		Stefan Rares Stelian: Proiect pentru gestiunea unui Restaurant
// Am ales gestiunea unui restaurant deoarece am lucrat in industria HORECA
// si sunt pasionat de managementul barurilor si restaurantelor.


class Masa
{
private:

	int nrMasa;					//Numarul mesei
	bool masaRezervata;			//Statusul mesei
	char* numeClient;			//Numele clientului care a rezervat masa (daca exista)
	int nrClientiZiPrecedenta;	//Numarul total de clienti la finalul zilei anterioare la masa nrMasa
	int* incasariZiPrecedenta;	//Incasarile inregistrate in ziua anterioara per client la masa nrMasa
	int nrTotal;				//Numarul total de mese din restaurant

public:

		Masa()
		{
			this->nrMasa = 3;
			this->masaRezervata = true;
			this->numeClient = new char[strlen("Popescu Andrei") + 1];
			strcpy(this->numeClient, "Popescu Andrei");
			this->nrClientiZiPrecedenta = 4;
			this->incasariZiPrecedenta = new int[nrClientiZiPrecedenta];
			for (int i = 0; i < nrClientiZiPrecedenta; i++)
				this->incasariZiPrecedenta[i] = i + 15;
			this->nrTotal = 30;
		}

		Masa(int nrMasa, bool masaRezervata)
		{
			this->nrMasa = nrMasa;
			this->masaRezervata = masaRezervata;
			this->numeClient = new char[strlen("Popescu Andrei") + 1];
			strcpy(this->numeClient, "Popescu Andrei");
			this->nrClientiZiPrecedenta = 4;
			this->incasariZiPrecedenta = new int[nrClientiZiPrecedenta];
			for (int i = 0; i < nrClientiZiPrecedenta; i++)
				this->incasariZiPrecedenta[i] = i + 15;
			this->nrTotal = 30;
		}
		
		Masa(int nrMasa, bool masaRezervata, const char* nume, int nrClientiZiPrecedenta, int* incasariZiPrecedenta,int nrTotal)
		{
			
			this->nrMasa = nrMasa;
			this->masaRezervata = masaRezervata;
			this->numeClient = new char[strlen(nume) + 1];
			strcpy(this->numeClient, nume);
			this->nrClientiZiPrecedenta = nrClientiZiPrecedenta;
			this->incasariZiPrecedenta = new int[nrClientiZiPrecedenta];
			for (int i = 0; i < nrClientiZiPrecedenta; i++)
				this->incasariZiPrecedenta[i] = incasariZiPrecedenta[i];
			this->nrTotal = nrTotal;
		}
		
		~Masa()
		{
			if (this->numeClient!=NULL)
				delete[]numeClient;
			if (this->incasariZiPrecedenta)
				delete incasariZiPrecedenta;
		}

		Masa(const Masa& masa1)
		{
			this->nrMasa = masa1.nrMasa;
			this->masaRezervata =masa1.masaRezervata;
			this->numeClient = new char[strlen(masa1.numeClient) + 1];
			strcpy(this->numeClient, masa1.numeClient);
			this->nrClientiZiPrecedenta = masa1.nrClientiZiPrecedenta;
			this->incasariZiPrecedenta = new int[masa1.nrClientiZiPrecedenta];
			for (int i = 0; i < masa1.nrClientiZiPrecedenta; i++)
				this->incasariZiPrecedenta[i] = masa1.incasariZiPrecedenta[i];
			this->nrTotal = masa1.nrTotal;
		}

		void afisareMasa()
		{
			cout << "			DETALII MASA		" << endl << endl;
			cout << " Numarul mesei: " << nrMasa << endl;
			cout << " Status rezervare: " << masaRezervata << endl;
			cout << " Nume client: " << numeClient << endl;
			cout << "______________________________________________________" << endl<<endl;
			cout << " Numar clienti zi precedenta: " << nrClientiZiPrecedenta << endl;
			for (int i = 0; i < nrClientiZiPrecedenta; i++)
				cout << "Vanzare client " << i + 1 << " : " << incasariZiPrecedenta[i] << " RON" << endl;
			cout << "______________________________________________________" << endl;
			cout << "					Numar mese: " << nrTotal << endl;
			

		}

		int getNrTotal()
		{
			return nrTotal;
		}

		int getNrMasa()
		{
			return nrMasa;
		}

		bool getStatusRezervare()
		{
			return masaRezervata;
		}

		char* getNumeClient()
		{
			return this->numeClient;
		}

		int getNrClientiZiPrecedenta()
		{
			return nrClientiZiPrecedenta;
		}

		int getIncasariZiPrecedenta(int i)
		{
			if (i >= 0 && i < this->nrClientiZiPrecedenta)
			{
				return this->incasariZiPrecedenta[i];
			}
		}

		void setNrTotal(int nrTotal)
		{
			if (nrTotal > 0)
			{
				this->nrTotal = nrTotal;
			}
		}

		void setNrMasa(int nrMasa)
		{
			if (nrMasa < nrTotal)
			{
				this->nrMasa = nrMasa;
			}
		}

		void setStatusRezervare(bool masaRezervata)
		{
			if (masaRezervata)
			{
				this->masaRezervata = masaRezervata;
			}
		}

		void setNumeClient(char* numeClient)
		{
			if (strlen(numeClient) > 0)
			{
				strcpy(this->numeClient,numeClient);
			}
		}

		void setNrClientiZiPrecedenta(int nrClienti)
		{
			if (nrClienti)
			{
				this->nrClientiZiPrecedenta = nrClienti;
			}
		}

		void setIncasariZiprecedenta(int nrClienti, int* incasariZiPrecedenta)
		{
			if (nrClienti >= 0 && incasariZiPrecedenta != NULL)
			{
				this->nrClientiZiPrecedenta = nrClienti;
				if (this->nrClientiZiPrecedenta)
				{
					delete[]this->incasariZiPrecedenta;

					this->incasariZiPrecedenta = new int[nrClienti];

					for (int i = 0; i < nrClienti; i++)
						this->incasariZiPrecedenta[i] = incasariZiPrecedenta[i];
				}
			}
		}

		const Masa operator=(const Masa& m)
		{
			if (this != &m)
			{
				this->nrMasa = m.nrMasa;
				this->nrTotal = m.nrTotal;
				this->masaRezervata = m.masaRezervata;
				this->nrClientiZiPrecedenta = m.nrClientiZiPrecedenta;
				if (this->numeClient)
				{
					delete[]this->numeClient;
				}
				this->numeClient = new char[strlen(m.numeClient) + 1];
				strcpy(this->numeClient, m.numeClient);
				if (this->incasariZiPrecedenta)
				{
					delete[]this->incasariZiPrecedenta;
				}
				this->incasariZiPrecedenta = new int[m.nrClientiZiPrecedenta];
				for (int i = 0; i < m.nrClientiZiPrecedenta; i++)
					this->incasariZiPrecedenta[i] = m.incasariZiPrecedenta[i];
			}
			return *this;

		}

		Masa operator*(const Masa& m)
		{
			Masa aux = *this;
			aux.nrTotal = this->nrTotal * m.nrTotal;
			aux.nrMasa = this->nrMasa * m.nrMasa;
			aux.nrClientiZiPrecedenta = this->nrClientiZiPrecedenta * m.nrClientiZiPrecedenta;
			if (aux.incasariZiPrecedenta)
				delete[]aux.incasariZiPrecedenta;
			for (int i = 0; i < this->nrClientiZiPrecedenta;i++)
				aux.incasariZiPrecedenta[i] = this->incasariZiPrecedenta[i];
			for (int i = this->nrClientiZiPrecedenta; i < aux.nrClientiZiPrecedenta; i++)
				aux.incasariZiPrecedenta[i] = this->incasariZiPrecedenta[i] * m.incasariZiPrecedenta[i];
			return aux;
		}

		explicit operator int()
		{
			if (this->nrClientiZiPrecedenta > 0)
			{
				float suma = 0;
				for (int i = 0; i < this->nrClientiZiPrecedenta; i++)
					suma += this->incasariZiPrecedenta[i];
				return suma;
			}
			else return 0;

		}

		explicit operator float()										// Realizeaza conversia in euro (1 EUR = 4.95 RON)
		{
			if (this->nrClientiZiPrecedenta > 0)
			{
				float suma = 0;
				float conversie;
				for (int i = 0; i < this->nrClientiZiPrecedenta; i++)
					suma += this->incasariZiPrecedenta[i];
				conversie = suma / 4.95;
				return conversie;

			}
			else return 0;

		}

		bool operator!=(const Masa& m)
		{
			if (this->masaRezervata == m.masaRezervata)
				return false;
			else return true;
		}
		
		int operator[](int index)
		{
			if (index >= 0 && index < nrClientiZiPrecedenta)
				return incasariZiPrecedenta[index];
		}

		Masa operator++()
		{
			this->nrClientiZiPrecedenta++;
			this->nrTotal++;
			return *this;
		}

		friend istream& operator>>(istream& i, Masa& m)
		{
			cout << " Numarul total de mese: ";
			i >> m.nrTotal;
			cout << " Numarul mesei: ";
			i >> m.nrMasa;
			cout << " Status rezervare: ";
			i >> m.masaRezervata;
			cout << " Nume rezervare: ";
			if (m.numeClient)
				delete[]m.numeClient;
			m.numeClient = new char[1000];
			i >> m.numeClient;
			cout << " Numar clienti zi precedenta: ";
			i >> m.nrClientiZiPrecedenta;
			cout << " Incasari zi precedenta: " << endl;
			if (m.incasariZiPrecedenta)
			{
				delete[]m.incasariZiPrecedenta;
			}
			if (m.nrClientiZiPrecedenta > 0)
			{
				m.incasariZiPrecedenta = new int[m.nrClientiZiPrecedenta];
				for (int p = 0; p < m.nrClientiZiPrecedenta; p++)
				{
					cout << "Suma incasata de la clientul " << p + 1 << " : ";
					i >> m.incasariZiPrecedenta[p];
				}
			}
			else m.incasariZiPrecedenta = NULL;
			return i;
		}

		friend ostream& operator<<(ostream& o, Masa& m)
		{
			cout << endl << endl;
			cout << "			DETALII MASA		" << endl << endl;
			cout << " Numarul mesei: ";
			o << m.nrMasa << endl;
			cout << " Status rezervare: ";
			o<< m.masaRezervata<< endl;
			cout << " Nume client: ";
			o<< m.numeClient << endl;
			cout << "______________________________________________________" << endl << endl;
			cout << " Numar clienti zi precedenta la masa ";
				o << m.nrMasa;
				cout << " :";
			o<< m.nrClientiZiPrecedenta << endl;
			for (int i = 0; i < m.nrClientiZiPrecedenta; i++)
			{
				cout << "Vanzare client " << i + 1 << " : ";
				o << m.incasariZiPrecedenta[i];
				cout << " RON" << endl;
			}
			
			cout << "______________________________________________________" << endl;
			cout << "					Numar mese: ";
			o<< m.nrTotal << endl;
			return o;
		}

		friend ofstream& operator<<(ofstream& out, Masa& m)
		{
			out << m.nrMasa << " ";
			out << m.masaRezervata << " ";
			out << m.numeClient << " ";
			out << m.nrClientiZiPrecedenta << " ";
			for (int i = 0; i < m.nrClientiZiPrecedenta; i++)
				out << m.incasariZiPrecedenta[i] << " ";
			out << endl;
			return out;
		}
		
		friend ifstream& operator>>(ifstream& in, Masa& m)
		{
			in >> m.nrMasa;
			in >> m.masaRezervata;
			in >> m.numeClient;
			in >> m.nrClientiZiPrecedenta;
			if (m.incasariZiPrecedenta != NULL)
				delete[]m.incasariZiPrecedenta;
			m.incasariZiPrecedenta = new int[m.nrClientiZiPrecedenta];
			for (int i = 0; i < m.nrClientiZiPrecedenta; i++)
				in >> m.incasariZiPrecedenta[i];
			return in;
		}

		void scrieCSV(ofstream& out)
		{
			out << this->nrMasa << ",";
			out << this->masaRezervata << ",";
			out << this->numeClient << ",";
			out << this->nrClientiZiPrecedenta << ",";
			for (int i = 0; i < this->nrClientiZiPrecedenta; i++)
				out << this->incasariZiPrecedenta[i] << ",";
			out << endl;
		}
};

class Ospatar
{
private:

	string numeOspatar;				//Numele Ospatarului
	int salariuOspatar;				//Salariul brut al Ospatarului (RON)
	int nrMeseDeServit;				//Numarul de mese de care se ocupa Ospatarul
	int* nrMeselorServite;			//Numerele meselor pe care le serveste Ospatarul
	const int nrOre;				//Numarul de ore de munca pe zi

public:

	Ospatar():nrOre(8)
	{
		this->numeOspatar = "Enache Marius";
		this->salariuOspatar=5000;
		this->nrMeseDeServit = 6;
		this->nrMeselorServite = new int[nrMeseDeServit];
		for (int i = 0; i < nrMeseDeServit; i++)
			this->nrMeselorServite[i] = i + 1;

	}

	Ospatar(string nume, int salariu, int nrMeseDeServit, int* nrMeselor, int ore) :nrOre(ore)
	{
		this->numeOspatar = nume;
		this->salariuOspatar=salariu;
		this->nrMeseDeServit = nrMeseDeServit;
		this->nrMeselorServite = new int[nrMeseDeServit];
		for (int i = 0; i < nrMeseDeServit; i++)
			this->nrMeselorServite[i] = nrMeselor[i];
	}

	~Ospatar()
	{
		if (this->nrMeselorServite);
		delete nrMeselorServite;
	}

	Ospatar(const Ospatar& osp) :nrOre(osp.nrOre)
	{
		numeOspatar = osp.numeOspatar;
		salariuOspatar = osp.salariuOspatar;
		nrMeseDeServit = osp.nrMeseDeServit;
		nrMeselorServite = new int[nrMeseDeServit];
		for (int i = 0; i < nrMeseDeServit; i++)
			nrMeselorServite[i] = osp.nrMeselorServite[i];
	}

	string getNumeOspatar()
	{
		return this->numeOspatar;
	}

	int getSalariuOspatar()
	{
		return salariuOspatar;
	}

	int getNrMeseDeServit()
	{
		return nrMeseDeServit;
	}

	int getNrMeseServite(int i)
	{
		if (i >= 0 && i < this->nrMeseDeServit)
			return nrMeselorServite[i];
	}

	const int getNrOre()
	{
		return nrOre;
	}

	void setNumeOspatar(string nume)
	{
		if (nume.length()>0)
		{
			this->numeOspatar=nume;
		}
	}

	void setSalariuOspatar(int salariu)
	{
		if (salariu > 0)
			salariuOspatar = salariu;
	}

	void setNrMeseDeServit(int nrMDS)
	{
		if (nrMDS > 0)
			this->nrMeseDeServit = nrMDS;
	}

	void setNrMeseServite(int nrMDS, int* nrMS)
	{
		if (nrMDS >= 0 && nrMS != NULL)
		{
			this->nrMeseDeServit = nrMDS;
			if (this->nrMeselorServite)
			{
				delete[]this->nrMeselorServite;

				this->nrMeselorServite = new int[nrMDS];

				for (int i = 0; i < nrMDS; i++)
					this->nrMeselorServite[i] = nrMS[i];
			}
		}
	}

	void afisareOspatar()
	{
		cout << "			OSPATAR		" << endl << endl;
		cout << " Nume: " << numeOspatar << endl;
		cout << " Salariu ospatar: " << salariuOspatar << endl;
		cout << " Numar de mese de servit: " <<nrMeseDeServit << endl;
		for (int i = 0; i < nrMeseDeServit; i++)
			cout << "		Masa " << nrMeselorServite[i] << endl;
		cout<<" Numar de ore muncite/zi: " << nrOre << endl;


	}

	const Ospatar& operator=(const Ospatar& o)
	{
		if (this != &o)
		{
			this->numeOspatar = o.numeOspatar;

			this->salariuOspatar = o.salariuOspatar;

			this->nrMeseDeServit = o.nrMeseDeServit;

			if (this->nrMeselorServite)
			{
				delete[]this->nrMeselorServite;
			}
			this->nrMeselorServite = new int[o.nrMeseDeServit];
			for (int i = 0; i < o.nrMeseDeServit; i++)
				this->nrMeselorServite[i] = o.nrMeselorServite[i];
		}
		return *this;
	}

	Ospatar operator+(const Ospatar& o)
	{
		Ospatar aux = *this;
		aux.salariuOspatar = this->salariuOspatar + o.salariuOspatar;
		aux.nrMeseDeServit = this->nrMeseDeServit + o.nrMeseDeServit;
		
		if (aux.nrMeselorServite)
			delete[]aux.nrMeselorServite;
		for (int i = 0; i < this->nrMeseDeServit; i++)
			aux.nrMeselorServite[i] = this->nrMeselorServite[i];
		for (int i = this->nrMeseDeServit; i < aux.nrMeseDeServit; i++)
			aux.nrMeselorServite[i] = this->nrMeselorServite[i] + o.nrMeselorServite[i];
		return aux;
	}

	int operator[](int index)
	{
		if (index >= 0 && index < nrMeseDeServit)
			return nrMeselorServite[index];
	}

	bool operator!=(const Ospatar& o)
	{
		if (this->nrMeseDeServit == o.nrMeseDeServit)
			return false;
		else return true;
	}

	explicit operator float()										// Realizeaza conversia in euro (1 EUR = 4.95 RON)
	{
		float bonus;

		if (this->nrMeseDeServit > 6&&this->nrMeseDeServit<9)
		{
			bonus = this->salariuOspatar*0.05;
			return bonus;
		}

		else if (this->nrMeseDeServit>=9)
		{
			bonus = this->salariuOspatar *0.10;
			return bonus;
		}
		
		else return 0;

	}

	friend istream& operator>>(istream& i, Ospatar& osp)
	{
		cout << " Nume Ospatar: ";
		getline(i, osp.numeOspatar);
		
		cout << " Salariu brut: "; 
		i >> osp.salariuOspatar;
		
		cout << " Numarul de mese de servit: ";
		i >> osp.nrMeseDeServit;
		
		cout << " Mesele servite: " << endl;
		if (osp.nrMeselorServite)
		{
			delete[]osp.nrMeselorServite;
		}
		if (osp.nrMeseDeServit > 0)
		{
			osp.nrMeselorServite = new int[osp.nrMeseDeServit];
			for (int p = 0; p < osp.nrMeseDeServit; p++)
			{
				cout << "Masa ";
				i >> osp.nrMeselorServite[p];
			}
		}
		else osp.nrMeselorServite = NULL;
		cout << " Numarul de ore muncite pe zi: 8 ";
		
		return i;
	}

	friend ostream& operator<<(ostream& o, Ospatar& osp)
	{
		cout << endl << endl;
		cout << "			OSPATAR		" << endl;
		cout << "______________________________________________________" << endl << endl;
		cout << " Nume: ";
		o << osp.numeOspatar<< endl;
		cout << " Salariu brut: ";
		o << osp.salariuOspatar << endl;
		cout << " Numarul meselor de servit: ";
		o << osp.nrMeseDeServit << endl;
		cout << " Mesele servite: " << endl;
		
		for (int i = 0; i < osp.nrMeseDeServit; i++)
		{
			cout << "	 Masa ";
			o << osp.nrMeselorServite[i];
			cout << endl;
		}

		
		cout << " Numarul orelor muncite pe zi: ";
		o << osp.nrOre << endl;
		cout << "______________________________________________________" << endl << endl;
		return o;
	}

	friend ofstream& operator<<(ofstream& out, Ospatar& o)
	{
		out << o.numeOspatar << " ";
		out << o.salariuOspatar << " ";
		out << o.nrMeseDeServit << " ";
		for (int i = 0; i < o.nrMeseDeServit; i++)
			out << o.nrMeselorServite[i] << " ";
		out << endl;
		return out;
	}
	
	friend ifstream& operator>>(ifstream& in, Ospatar& o)
	{
		in >> o.numeOspatar;
		in >> o.salariuOspatar;
		in >> o.nrMeseDeServit;
		if (o.nrMeselorServite != NULL)
			delete[]o.nrMeselorServite;
		o.nrMeselorServite = new int[o.nrMeseDeServit];
		for (int i = 0; i < o.nrMeseDeServit; i++)
			in >> o.nrMeselorServite[i];
		return in;
	}

	void scrieCSV(ofstream& out)
	{
		out << this->numeOspatar << ",";
		out << this->salariuOspatar << ",";
		out << this->nrMeseDeServit << ",";
		for (int i = 0; i < this->nrMeseDeServit; i++)
			out << this->nrMeselorServite[i] << ",";
		out << endl;
	}

	virtual void afiseazaDescriere()
	{
		cout << *this << endl << endl;
	}

	void descrieOspatar()
	{
		afiseazaDescriere();
	}
};

class Barman
{
private:
	string numeBarman;				//Numele barmanului
	int salariuBarman;				//Salariul brut al barmanului
	const int nrOreB;				//Numarul de ore de munca pe zi
	bool atestat;					//Detinerea unui atestat de barman
	int nrZile;						//Numarul de zile lucrat in saptamana anterioara
	int* comision;					//Comisionul primit de la ospatari din vanzarile de bauturi la mese in zilele in care barmanul a muncit

public:

	Barman():nrOreB(8)
	{
		this->numeBarman = "Ionescu Vlad";
		this->salariuBarman = 4500;
		this->atestat = true;
		this->nrZile = 5;
		this->comision = new int[nrZile];
		for (int i = 0; i < this->nrZile; i++)
			this->comision[i] = i + 5;
	}

	Barman(string nume, int salariu, bool atestat, int nrZile, int* comisionb, int ore) :nrOreB(ore)
	{
		this->numeBarman = nume;
		this->salariuBarman = salariu;
		this->atestat = atestat;
		this->nrZile = nrZile;
		this->comision = new int[nrZile];
		for (int i = 0; i < nrZile; i++)
			this->comision[i] = comisionb[i];

	}
	
	~Barman()
	{
		if (this->comision)
			delete this->comision;
	}
	
	Barman(const Barman& b) :nrOreB(b.nrOreB)
	{
		numeBarman = b.numeBarman;
		salariuBarman = b.salariuBarman;
		atestat = b.atestat;
		nrZile = b.nrZile;
		comision = new int[nrZile];
		for (int i = 0; i < b.nrZile; i++)
			comision[i] = b.comision[i];
	}

	string getNumeBarman()
	{
		return numeBarman;
	}

	int getSalariuBarman()
	{
		return salariuBarman;
	}

	bool getAtestat()
	{
		return atestat;
	}

	int getNrZile()
	{
		return nrZile;
	}

	int getComision(int i)
	{
		for (i = 0; i < this->nrZile; i++)
			return comision[i];
	}

	const int getNrOreB()
	{
		return nrOreB;
	}

	void setNumeBarman(string nume)
	{
		if (nume.length() > 0)
		{
			this->numeBarman = nume;
		}
	}

	void setSalariuBarman(int salariu)
	{
		if (salariu > 0)
			this->salariuBarman = salariu;
	}

	void setAtestat(bool atestat)
	{
		if (atestat)
		{
			this->atestat = atestat;
		}
	}

	void setNrZile(int nrZ)
	{
		if (nrZ > 0)
			this->nrZile = nrZ;
	}

	void setComision(int nrZ, int* comision)
	{
		if (nrZ >= 0 && nrZ != NULL)
		{
			this->nrZile = nrZ;
			if (this->comision)
			{
				delete[]this->comision;

				this->comision = new int[nrZ];

				for (int i = 0; i < nrZ; i++)
					this->comision[i] = comision[i];
			}
		}
	}

	void afisareBarman()
	{

		cout << "			Barman	" << endl << endl;
		cout << " Nume: " << numeBarman << endl;
		cout << " Salariu: " << salariuBarman << endl;
		cout << " Atestat: " << atestat << endl;
		cout << " Numarul de zile muncite din saptamana anterioara: " << nrZile << endl;
		for (int i = 0; i < nrZile; i++)
			cout << "		Comision ziua " << i+1 <<": "<<comision[i]<< endl;
		cout << " Numar de ore muncite/zi: " << nrOreB << endl;

	}

	const Barman operator=(const Barman& b)
	{
		if (this != &b)
		{
			this->numeBarman = b.numeBarman;

			this->salariuBarman = b.salariuBarman;

			this->atestat = b.atestat;

			this->nrZile = b.nrZile;

			if (this->comision)
			{
				delete[]this->comision;
			}
			this->comision = new int[b.nrZile];
			for (int i = 0; i < b.nrZile; i++)
				this->comision[i] = b.comision[i];
		}
		return *this;
	}

	Barman operator+(const Barman& b)
	{
		Barman aux = *this;
		
		aux.salariuBarman = this->salariuBarman + b.salariuBarman;
		
		aux.nrZile = this->nrZile + b.nrZile;

		if (aux.comision)
			delete[]aux.comision;
		for (int i = 0; i < this->nrZile; i++)
			aux.comision[i] = this->comision[i];
		for (int i = this->nrZile; i < aux.nrZile; i++)
			aux.comision[i] = this->comision[i] + b.comision[i];
		return aux;
	}

	int operator[](int index)
	{
		if (index >= 0 && index < nrZile)
			return comision[index];
	}

	bool operator!=(const Barman& b)
	{
		if (this->atestat == b.atestat)
			return false;
		else return true;
	}

	explicit operator int()										// Realizeaza suma totala a comisionului incasat din saptamana anterioara
	{
		int totalComision=0;

		for (int i = 0; i < this->nrZile;i++)
		{
			totalComision = totalComision + comision[i];
		}
		
		return totalComision;
	}

	friend istream& operator>>(istream& i, Barman& b)
	{
		cout << " Nume Barman: ";
		getline(i, b.numeBarman);
		
		cout << " Salariu brut: ";
		i >> b.salariuBarman;

		cout << " Atestat: ";
		i >> b.atestat;

		cout << " Numarul de zile muncite din saptamana anterioara: ";
		i >> b.nrZile;
		
		cout << " Comision pe fiecare zi muncita: " << endl;
		if (b.comision)
		{
			delete[]b.comision;
		}
		if (b.nrZile > 0)
		{
			b.comision = new int[b.nrZile];
			for (int p = 0; p < b.nrZile; p++)
			{
				cout << "Comision in ziua "<< p+1 <<": ";
				i >> b.comision[p];
			}
		}
		else b.comision = NULL;
		
		cout << " Numarul de ore muncite pe zi: 8 ";

		return i;
	}

	friend ostream& operator<<(ostream& o, Barman& b)
	{
		cout << endl << endl;

		cout << "			BARMAN		" << endl;

		cout << "_____________________________________________________________" << endl << endl;

		cout << " Nume: ";
		o << b.numeBarman << endl;

		cout << " Salariu brut: ";
		o << b.salariuBarman << endl;

		cout << " Atestat: ";
		o << b.atestat << endl;

		cout << " Numarul de zile muncite in saptamana anterioara: ";
		o << b.nrZile << endl;

		cout << " Comision pe fiecare zi muncita:" << endl;

		for (int i = 0; i < b.nrZile; i++)
		{
			cout << "	 Comision ziua "<<i+1<<": ";
			o << b.comision[i];
			cout << endl;
		}


		cout << " Numarul orelor muncite pe zi: ";
		o << b.nrOreB << endl;

		cout << "_____________________________________________________________" << endl << endl;

		return o;
	}

	friend ofstream& operator<<(ofstream& out, Barman& b)
	{
		out << b.numeBarman << " ";
		out << b.salariuBarman << " ";
		out << b.atestat << " ";
		out << b.nrZile << " ";
		for (int i = 0; i < b.nrZile; i++)
			out << b.comision[i] << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Barman& b)
	{
		in >> b.numeBarman;
		in >> b.salariuBarman;
		in >> b.atestat;
		in >> b.nrZile;
		if (b.comision != NULL)
			delete[]b.comision;
		b.comision = new int[b.nrZile];
		for (int i = 0; i < b.nrZile; i++)
			in >> b.comision[i];
		return in;
	}

	void scrieCSV(ofstream& out)
	{
		out << this->numeBarman << ",";
		out << this->salariuBarman << ",";
		out << this->atestat << ",";
		out << this->nrZile << ",";
		for (int i = 0; i < this->nrZile; i++)
			out << this->comision[i] << ",";
		out << endl;
	}

	virtual void afiseazaDescriere()
	{
		cout << *this << endl << endl;
	}

	void descrieBarman()
	{
		afiseazaDescriere();
	}
};

class Bucatar
{
private:
	string numeBucatar;				//Numele bucatarului
	int salariuBucatar;				//Salariul brut al bucatarului
	const int nrOreBu;				//Numarul de ore de munca pe zi
	int nrZileB;					//Numarul de zile lucrat in saptamana anterioara
	int* comisionB;					//Comisionul primit de la ospatari din vanzarile de mancare la mese in zilele in care bucatarul a muncit

public:
	
	Bucatar():nrOreBu(8)
	{
		this->numeBucatar = "Gheorghe Vlad";
		this->salariuBucatar = 5000;
		this->nrZileB = 5;
		this->comisionB = new int[nrZileB];
		for (int i = 0; i < this->nrZileB; i++)
			this->comisionB[i] = i + 5;
	}

	Bucatar(string nume, int salariu, int nrZ, int* comision, int nrO) :nrOreBu(nrO)
	{
		this->numeBucatar = nume;
		this->salariuBucatar = salariu;
		this->nrZileB = nrZ;
		this->comisionB = new int[nrZ];
		for (int i = 0; i < nrZ; i++)
			this->comisionB[i] = comision[i];
	}

	~Bucatar()
	{
		if (this->comisionB)
			delete this->comisionB;
	}

	Bucatar(const Bucatar& b) :nrOreBu(b.nrOreBu)
	{
		numeBucatar = b.numeBucatar;
		salariuBucatar = b.salariuBucatar;
		nrZileB = b.nrZileB;
		comisionB = new int[nrZileB];
		for (int i = 0; i < b.nrZileB; i++)
			comisionB[i] = b.comisionB[i];
	}

	string getNumeBucatar()
	{
		return numeBucatar;
	}

	int getSalariuBucatar()
	{
		return salariuBucatar;
	}

	int getNrZileB()
	{
		return nrZileB;
	}

	int getComisionB(int i)
	{
		for (i = 0; i < this->nrZileB; i++)
			return comisionB[i];
	}

	const int getNrOreBu()
	{
		return nrOreBu;
	}

	void setNumeBucatar(string nume)
	{
		if (nume.length() > 0)
		{
			this->numeBucatar = nume;
		}
	}

	void setSalariuBucatar(int salariu)
	{
		if (salariu > 0)
			this->salariuBucatar = salariu;
	}

	void setNrZileB(int nrZ)
	{
		if (nrZ > 0)
			this->nrZileB = nrZ;
	}

	void setComisionB(int nrZ, int* comision)
	{
		if (nrZ >= 0 && nrZ != NULL)
		{
			this->nrZileB = nrZ;
			if (this->comisionB)
			{
				delete[]this->comisionB;

				this->comisionB = new int[nrZ];

				for (int i = 0; i < nrZ; i++)
					this->comisionB[i] = comision[i];
			}
		}
	}

	void afisareBucatar()
	{

		cout << "			Bucatar	" << endl << endl;
		cout << " Nume: " << numeBucatar << endl;
		cout << " Salariu: " << salariuBucatar<< endl;
		cout << " Numarul de zile muncite din saptamana anterioara: " << nrZileB << endl;
		for (int i = 0; i < nrZileB; i++)
			cout << "		Comision ziua " << i + 1 << ": " << comisionB[i] << endl;
		cout << " Numar de ore muncite/zi: " << nrOreBu << endl;

	}

	const Bucatar operator=(const Bucatar& b)
	{
		if (this != &b)
		{
			this->numeBucatar = b.numeBucatar;

			this->salariuBucatar = b.salariuBucatar;

			this->nrZileB = b.nrZileB;

			if (this->comisionB)
			{
				delete[]this->comisionB;
			}
			this->comisionB = new int[b.nrZileB];
			for (int i = 0; i < b.nrZileB; i++)
				this->comisionB[i] = b.comisionB[i];
		}

		return *this;
	}

	Bucatar operator+(const Bucatar& b)
	{
		Bucatar aux = *this;

		aux.salariuBucatar = this->salariuBucatar + b.salariuBucatar;

		aux.nrZileB = this->nrZileB + b.nrZileB;

		if (aux.comisionB)
			delete[]aux.comisionB;
		for (int i = 0; i < this->nrZileB; i++)
			aux.comisionB[i] = this->comisionB[i];
		for (int i = this->nrZileB; i < aux.nrZileB; i++)
			aux.comisionB[i] = this->comisionB[i] + b.comisionB[i];
		return aux;
	}

	bool operator!=(const Bucatar& b)
	{
		if (this->salariuBucatar == b.salariuBucatar)
			return false;
		else return true;
	}

	int operator[](int index)
	{
		if (index >= 0 && index < nrZileB)
			return comisionB[index];
	}

	explicit operator int()										// Realizeaza suma totala a comisionului incasat din saptamana anterioara
	{
		int totalComisionB = 0;

		for (int i = 0; i < this->nrZileB; i++)
		{
			totalComisionB = totalComisionB + comisionB[i];
		}

		return totalComisionB;
	}

	friend istream& operator>>(istream& i, Bucatar& b)
	{
		cout << " Nume Bucatar: ";
		getline(i, b.numeBucatar);

		cout << " Salariu brut: ";
		i >> b.salariuBucatar;

		cout << " Numarul de zile muncite din saptamana anterioara: ";
		i >> b.nrZileB;

		cout << " Comision pe fiecare zi muncita: " << endl;
		if (b.comisionB)
		{
			delete[]b.comisionB;
		}
		if (b.nrZileB > 0)
		{
			b.comisionB = new int[b.nrZileB];
			for (int p = 0; p < b.nrZileB; p++)
			{
				cout << "Comision in ziua " << p + 1 << ": ";
				i >> b.comisionB[p];
			}
		}
		else b.comisionB = NULL;

		cout << " Numarul de ore muncite pe zi: 8 ";

		return i;
	}

	friend ostream& operator<<(ostream& o, Bucatar& b)
	{
		cout << endl << endl;

		cout << "			BUCATAR		" << endl;

		cout << "_____________________________________________________________" << endl << endl;

		cout << " Nume: ";
		o << b.numeBucatar << endl;

		cout << " Salariu brut: ";
		o << b.salariuBucatar << endl;

		cout << " Numarul de zile muncite in saptamana anterioara: ";
		o << b.nrZileB << endl;

		cout << " Comision pe fiecare zi muncita:" << endl;

		for (int i = 0; i < b.nrZileB; i++)
		{
			cout << "	 Comision ziua " << i + 1 << ": ";
			o << b.comisionB[i];
			cout << endl;
		}


		cout << " Numarul orelor muncite pe zi: ";
		o << b.nrOreBu << endl;

		cout << "_____________________________________________________________" << endl << endl;

		return o;
	}

	friend ofstream& operator<<(ofstream& out, Bucatar& b)
	{
		out << b.numeBucatar << " ";
		out << b.salariuBucatar << " ";
		out << b.nrZileB << " ";
		for (int i = 0; i < b.nrZileB; i++)
			out << b.comisionB[i] << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Bucatar& b)
	{
		in >> b.numeBucatar;
		in >> b.salariuBucatar;
		in >> b.nrZileB;
		if (b.comisionB != NULL)
			delete[]b.comisionB;
		b.comisionB = new int[b.nrZileB];
		for (int i = 0; i < b.nrZileB; i++)
			in >>b.comisionB[i];
		return in;
	}

	void scrieCSV(ofstream& out)
	{
		out << this->numeBucatar << ",";
		out << this->salariuBucatar << ",";
		out << this->nrZileB << ",";
		for (int i = 0; i < this->nrZileB; i++)
			out << this->comisionB[i] << ",";
		out << endl;
	}

	virtual void afiseazaDescriere()
	{
		cout << *this << endl << endl;
	}

	void descrieBucatar()
	{
		afiseazaDescriere();
	}

};


enum CategorieMarfa{bar=1, bucatarie, curatenie};

std::istream& operator>>(std::istream& is, CategorieMarfa& categorie) {
	std::string text;
	if (is >> text) {
		if (text == "bar") 
		{
			categorie = bar;
		}

		else if (text == "bucatarie")
		{
			categorie = bucatarie;
		}

		else if (text == "curatenie")
		{
			categorie = curatenie;
		}
	
	}
	return is;
}

class MarfaAbstract
{
public:
	virtual void descrieMarfa() = 0;
	virtual ~MarfaAbstract()
	{

	}

};

class Marfa:public MarfaAbstract
{
private:
	static int numarComanda;			// Numarul(ID) comenzii
	CategorieMarfa categorie;			// Categoria marfii
	int valoareMarfa;					// Valoarea totala a comenzii
	int nrComenzi;						// Numarul de comenzi din luna anterioara
	int* valoareComenzi;				// Valoarea fiecarei comenzi de marfa din luna anterioara

public:

	Marfa()
	{
		numarComanda++;
		this->categorie = bucatarie;
		this->valoareMarfa = 4735;
		this->nrComenzi = 3;
		this->valoareComenzi = new int[nrComenzi];
		for (int i = 0; i < this->nrComenzi; i++)
			this->valoareComenzi[i] = i + 300;
	}

	Marfa(static int id, CategorieMarfa categorie, int valoare, int nrComenzi, int* valoareComenzi)
	{
		numarComanda++;
		this->categorie = categorie;
		this->valoareMarfa = valoare;
		this->nrComenzi = nrComenzi;
		this->valoareComenzi = new int[nrComenzi];
		for (int i = 0; i < nrComenzi; i++)
			this->valoareComenzi[i] = valoareComenzi[i];
	}

	~Marfa()
	{
		if (this->valoareComenzi)
			delete this->valoareComenzi;
	}

	Marfa(const Marfa& m)
	{
		numarComanda++;
		categorie = m.categorie;
		valoareMarfa = m.valoareMarfa;
		nrComenzi = m.nrComenzi;
		valoareComenzi = new int[m.nrComenzi];
		for (int i = 0; i < m.nrComenzi; i++)
			valoareComenzi[i] = m.valoareComenzi[i];
	}

	static int getNumarComanda()
	{
		return numarComanda;
	}

	CategorieMarfa getCategorie()
	{
		return this->categorie;
	}

	int getValoareMarfa()
	{
		return this->valoareMarfa;
	}

	int getNrComenzi()
	{
		return this->nrComenzi;
	}

	int getValoareComenzi(int i)
	{
		for (i = 0; i < this->nrComenzi; i++)
			return valoareComenzi[i];
	}

	void setCategorie(CategorieMarfa c)
	{
		if (c == bar || c == bucatarie || c == curatenie)
			this->categorie = c;
	}

	void setValoareMarfa(int val)
	{
		if (val > 0)
			this->valoareMarfa = val;
	}

	void setNrComenzi(int nrC)
	{
		if (nrC > 0)
			this->nrComenzi = nrC;
	}

	void setValoareComenzi(int nrC, int* valC)
	{
		if (nrC >= 0)
		{
			this->nrComenzi = nrC;
			if (this->valoareComenzi)
			{
				delete[]this->valoareComenzi;

				this->valoareComenzi = new int[nrC];

				for (int i = 0; i < nrC; i++)
					this->valoareComenzi[i] = valC[i];
			}
		}
	}

	void afisareMarfa()
	{
		cout << "			Marfa	" << endl << endl;
		cout << " Numar comanda: " << numarComanda << endl;
		cout << " Categorie: " << categorie;
		cout << "		 (1-BAR			2-BUCATARIE			3-CURATENIE)" << endl;
		cout << " Valoare comanda: " << valoareMarfa << " RON" << endl;
		cout << " Numarul de comenzi de marfa din luna anterioara: " << nrComenzi << endl;
		for (int i = 0; i < nrComenzi; i++)
			cout << "		Valoare comanda " << i + 1 << ": " << valoareComenzi[i] << endl;
	}

	const Marfa operator=(const Marfa& m)
	{
		if (this != &m)
		{
			this->categorie = m.categorie;

			this->valoareMarfa = m.valoareMarfa;

			this->nrComenzi = m.nrComenzi;

			if (this->valoareComenzi)
			{
				delete[]this->valoareComenzi;
			}
			this->valoareComenzi = new int[m.nrComenzi];
			for (int i = 0; i < m.nrComenzi; i++)
				this->valoareComenzi[i] = m.valoareComenzi[i];
		}
		return *this;
	}

	Marfa operator+(const Marfa& m)
	{
		Marfa aux = *this;

		aux.valoareMarfa = this->valoareMarfa + m.valoareMarfa;

		aux.nrComenzi = this->nrComenzi + m.nrComenzi;

		if (aux.valoareComenzi)
			delete[]aux.valoareComenzi;
		for (int i = 0; i < this->nrComenzi; i++)
			aux.valoareComenzi[i] = this->valoareComenzi[i];
		for (int i = this->nrComenzi; i < aux.nrComenzi; i++)
			aux.valoareComenzi[i] = this->valoareComenzi[i] + m.valoareComenzi[i];
		return aux;
	}

	bool operator!=(const Marfa& m)
	{
		if (this->valoareMarfa == m.valoareMarfa)
			return false;
		else return true;
	}

	int operator[](int index)
	{
		if (index >= 0 && index < nrComenzi)
			return valoareComenzi[index];
	}

	explicit operator int()
	{
		if (this->nrComenzi > 0)
		{
			float suma = 0;
			for (int i = 0; i < this->nrComenzi; i++)
				suma += this->valoareComenzi[i];
			return suma;
		}
		else return 0;

	}

	explicit operator float()										// Calculeaza TVA-ul total din luna anterioara
	{
		if (this->nrComenzi > 0)
		{
			float suma = 0;
			float tva;
			for (int i = 0; i < this->nrComenzi; i++)
				suma += this->valoareComenzi[i];
			tva = suma *0.19;
			return tva;

		}
		else return 0;

	}

	Marfa& operator--()
	{
		if (this->nrComenzi >= 0)
		{
			this->nrComenzi--;
			int* v = new int[this->nrComenzi];
			if (valoareComenzi != NULL)
			{
				for (int i = 0; i < this->nrComenzi; i++)
					v[i] = valoareComenzi[i];
				delete[] valoareComenzi;
			}
			this->valoareComenzi = v;
		}
		else
		{
			this->valoareComenzi = NULL;
		}
		return *this;
	}

	Marfa& operator++()
	{
		if (this->nrComenzi >= 0)
		{
			this->nrComenzi++;
			int* v = new int[this->nrComenzi];
			if (valoareComenzi != NULL)
			{
				for (int i = 0; i < this->nrComenzi; i++)
					v[i] = valoareComenzi[i];
				delete[] valoareComenzi;
			}
			this->valoareComenzi = v;
		}
		else
		{
			this->valoareComenzi = NULL;
		}
		return *this;
	}

	friend istream& operator>>(istream& i, Marfa& m)
	{
		/*cout << " ID Comanda: ";
		i >> m.numarComanda;*/
		cout << " Valoare comanda: ";
		i >> m.valoareMarfa;
		cout << " Categorie marfa (bar/bucatarie/curatenie): ";
		i >> m.categorie;
		cout << " Numar comenzi in luna anterioara: ";
		i >> m.nrComenzi;
		cout << " Valoare comenzi: " << endl;
		if (m.valoareComenzi)
		{
			delete[]m.valoareComenzi;
		}
		if (m.nrComenzi > 0)
		{
			m.valoareComenzi = new int[m.nrComenzi];
			for (int p = 0; p < m.nrComenzi; p++)
			{
				cout << "Valoare comanda " << p + 1 << " : ";
				i >> m.valoareComenzi[p];
			}
		}
		else m.valoareComenzi = NULL;
		return i;
	}

	friend ostream& operator<<(ostream& o, Marfa& m)
	{
		cout << endl << endl;
		cout << "			MARFA		" << endl << endl;
		cout << " ID Comanda: ";
		o << m.numarComanda << endl;
		cout << " Valoare comanda: ";
		o << m.valoareMarfa << endl;
		cout << " Categorie marfa: ";
		o << m.categorie << endl;
		cout << "______________________________________________________" << endl << endl;
		cout << " Numar comenzi in luna anterioara : ";
		o << m.nrComenzi << endl;
		for (int i = 0; i < m.nrComenzi; i++)
		{
			cout << "		Comanda " << i + 1 << " : ";
			o << m.valoareComenzi[i];
			cout << " RON" << endl;
		}
		cout << "______________________________________________________" << endl;
		
		return o;
	}

	friend ofstream& operator<<(ofstream& out, Marfa& m)
	{
		out << m.numarComanda << " ";
		out << m.valoareMarfa << " ";
		out << m.categorie << " ";
		out << m.nrComenzi << " ";
		for (int i = 0; i < m.nrComenzi; i++)
			out << m.valoareComenzi[i] << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Marfa& m)
	{
		in >> m.numarComanda;
		in >> m.valoareMarfa;
		in >> m.categorie;
		in >> m.nrComenzi;
		if (m.valoareComenzi != NULL)
			delete[]m.valoareComenzi;
		m.valoareComenzi = new int[m.nrComenzi];
		for (int i = 0; i < m.nrComenzi; i++)
			in >> m.valoareComenzi[i];
		return in;
	}

	void scrieCSV(ofstream& out)
	{
		out << this->numarComanda << ",";
		out << this->valoareMarfa << ",";
		out << this->categorie << ",";
		out << this->nrComenzi << ",";
		for (int i = 0; i < this->nrComenzi; i++)
			out << this->valoareComenzi[i] << ",";
		out << endl;
	}

	virtual void afiseazaDescriere()
	{
		cout << *this << endl << endl;
	}

	void descrieMarfa()
	{
		afiseazaDescriere();
	}
};

int Marfa::numarComanda = 0;

class Angajati
{
private:
	int nrBarmani;
	Barman** barmani;
	int nrOspatari;
	Ospatar** ospatari;
	int nrBucatari;
	Bucatar** bucatari;

public:

	int getNrBarmani()const
	{
		return this->nrBarmani;
	}

	Barman** getBarmani()
	{
		return this->barmani;
	}

	int getNrOspatari()const
	{
		return this->nrOspatari;
	}

	Ospatar** getOspatari()
	{
		return this->ospatari;
	}

	int getNrBucatari()const
	{
		return this->nrBucatari;
	}

	Bucatar** getBucatari()
	{
		return this->bucatari;
	}

	Angajati()
	{
		nrBarmani = 0;
		barmani = NULL;
		nrOspatari = 0;
		ospatari = NULL;
		nrBucatari = 0;
		bucatari = NULL;

	}

	Angajati(int nrBarmani, Barman** barmani, int nrOspatari, Ospatar** ospatari, int nrBucatari, Bucatar** bucatari)
	{
		this->nrBarmani=nrBarmani;
		if (this->nrBarmani != 0)
		{
			this->barmani = new Barman * [nrBarmani];
			for (int i = 0; i < nrBarmani; i++)
				this->barmani[i] = barmani[i];
		}
		else barmani = NULL;

		this->nrOspatari = nrOspatari;
		if (this->nrOspatari != 0)
		{
			this->ospatari = new Ospatar * [nrOspatari];
			for (int i = 0; i < nrOspatari; i++)
				this->ospatari[i] = ospatari[i];
		}
		else ospatari = NULL;

		this->nrBucatari = nrBucatari;
		if (this->nrBucatari != 0)
		{
			this->bucatari = new Bucatar * [nrBucatari];
			for (int i = 0; i < nrBucatari; i++)
				this->bucatari[i] = bucatari[i];
		}
		else bucatari = NULL;

	}

	void afisareAngajati()
	{
		cout << " Numar barmani: " << nrBarmani << endl;
		for (int i = 0; i < nrBarmani; i++)
			cout << "Barman " << i << ":" << endl << barmani[i] << endl;

		cout << " Numar ospatari: " << nrOspatari << endl;
		for (int i = 0; i < nrOspatari; i++)
			cout << "Ospatar " << i << ":" << endl << ospatari[i] << endl;

		cout << " Numar barmani: " << nrBarmani << endl;
		for (int i = 0; i < nrBarmani; i++)
			cout << "Barman " << i << ":" << endl << barmani[i] << endl;

		cout << " Numar bucatari: " << nrBucatari << endl;
		for (int i = 0; i < nrBucatari; i++)
			cout << "Bucatar " << i << ":" << endl << bucatari[i] << endl;
	}

	const Angajati& operator=(const Angajati& ang)
	{
		if (this != &ang)
		{
			this->nrBarmani = ang.nrBarmani;
			this->nrOspatari = ang.nrOspatari;
			this->nrBucatari = ang.nrBucatari;
			
			if (this->barmani != NULL)
					delete[]this->barmani;

			if (this->nrBarmani > 0)
			{
				this->barmani = new Barman * [ang.nrBarmani];
				for (int i = 0; i < ang.nrBarmani; i++)
					this->barmani[i] = ang.barmani[i];
			}
			else this->barmani = NULL;

			if (this->ospatari != NULL)
				delete[]this->ospatari;

			if (this->nrOspatari > 0)
			{
				this->ospatari = new Ospatar * [ang.nrOspatari];
				for (int i = 0; i < ang.nrOspatari; i++)
					this->ospatari[i] = ang.ospatari[i];
			}
			else this->ospatari = NULL;

			if (this->bucatari != NULL)
				delete[]this->bucatari;

			if (this->nrBucatari > 0)
			{
				this->bucatari = new Bucatar * [ang.nrBucatari];
				for (int i = 0; i < ang.nrBucatari; i++)
					this->bucatari[i] = ang.bucatari[i];
			}
			else this->bucatari = NULL;
		}
		return *this;
	}

	Angajati(const Angajati& ang)
	{


		this->nrBarmani = ang.nrBarmani;
		this->nrOspatari = ang.nrOspatari;
		this->nrBucatari = ang.nrBucatari;

		if (this->nrBarmani > 0)
		{
			this->barmani = new Barman * [ang.nrBarmani];
			for (int i = 0; i < ang.nrBarmani; i++)
				this->barmani[i] = ang.barmani[i];
		}
		else this->barmani = NULL;

		if (this->ospatari != NULL)
			delete[]this->ospatari;

		if (this->nrOspatari > 0)
		{
			this->ospatari = new Ospatar * [ang.nrOspatari];
			for (int i = 0; i < ang.nrOspatari; i++)
				this->ospatari[i] = ang.ospatari[i];
		}
		else this->ospatari = NULL;

		if (this->bucatari != NULL)
			delete[]this->bucatari;

		if (this->nrBucatari > 0)
		{
			this->bucatari = new Bucatar * [ang.nrBucatari];
			for (int i = 0; i < ang.nrBucatari; i++)
				this->bucatari[i] = ang.bucatari[i];
		}
		else this->bucatari = NULL;

	}

	~Angajati()
	{
		if (this->barmani)
			delete[]this->barmani;

		if (this->ospatari)
			delete[]this->ospatari;

		if (this->bucatari)
			delete[]this->bucatari;
	}

};

enum CategorieProdus { bautura = 1, mancare};

std::istream& operator>>(std::istream& is, CategorieProdus& categorie) {
	std::string text;
	if (is >> text) 
	{
		if (text == "bautura" || text=="1")
		{
			categorie = bautura;
		}

		else if (text == "mancare" || text=="2")
		{
			categorie = mancare;
		}
	}
	return is;
}

class Produs
{
private:
	CategorieProdus tipProdus;
	string numeProdus;
	int pretProdus;
	int cantitate;

public:

	Produs()
	{
		this->tipProdus = mancare;
		this->numeProdus = "Pizza";
		this->pretProdus = 30;
		this->cantitate = 450;
	}

	Produs(CategorieProdus tip, string nume, int pret, int cantitate)
	{
		this->tipProdus = tip;
		this->numeProdus = nume;
		this->pretProdus = pret;
		this->cantitate = cantitate;
	}

	Produs(const Produs& m)
	{
		this->tipProdus = m.tipProdus;
		this->numeProdus = m.numeProdus;
		this->pretProdus = m.pretProdus;
		this->cantitate = m.cantitate;
	}

	CategorieProdus getTipProdus()
	{
		return this->tipProdus;
	}

	string getNumeProdus()
	{
		return this->numeProdus;
	}

	int getPretProdus()
	{
		return this->pretProdus;
	}

	int getCantitate()
	{
		return this->cantitate;
	}

	void setTipProdus(CategorieProdus t)
	{
		if (t == bautura || t == mancare)
			this->tipProdus = t;
	}

	void setNumeProdus(string n)
	{
		if (n.length() > 0)
			this->numeProdus = n;
	}

	void setPretProdus(int p)
	{
		if (p > 0)
			this->pretProdus = p;
	}

	void setCantitate(int c)
	{
		if (c > 0)
			this->cantitate = c;
	}

	void afisareProdus()
	{
		cout << " Categorie: " << tipProdus << endl;
		cout << " Nume: " << numeProdus << endl;
		cout << " Pret: " << pretProdus << endl;
		cout << " Cantitate: " << cantitate;
		if (tipProdus == bautura)
		{
			cout << "ML" << endl;
		}
		else if (tipProdus == mancare)
		{
			cout << "G" << endl;
		}
	}

	Produs operator+(const Produs& p)
	{
		Produs aux = *this;
		aux.pretProdus = this->pretProdus + p.pretProdus;
		aux.cantitate = this->cantitate + p.cantitate;
	}

	Produs operator-(const Produs& p)
	{
		Produs aux = *this;
		aux.pretProdus = this->pretProdus - p.pretProdus;
		aux.cantitate = this->cantitate - p.cantitate;
	}

	friend istream& operator>>(istream& i, Produs& p)
	{
		cout << " Tip produs (1-bautura    2-mancare): ";
		i >> p.tipProdus;
		cout << " Nume produs: ";
		cin.get();
		getline(i, p.numeProdus);
		cout << " Pret: ";
		i >> p.pretProdus;
		cout << " Cantitate: ";
		i >> p.cantitate;
		cout << endl;
		return i;
	}

	friend ostream& operator<<(ostream& o,const Produs& p)
	{
		o << " Categorie: " << p.tipProdus << endl;
		o << " Nume: " << p.numeProdus << endl;
		o << " Pret: " << p.pretProdus <<" RON"<< endl;
		o << " Cantitate: " << p.cantitate;
		if (p.tipProdus == bautura || p.tipProdus==1)
		{
			o << "ML" << endl;
		}
		else if (p.tipProdus == mancare || p.tipProdus==2)
		{
			o << "G" << endl;
		}
		return o;
	}

	friend ofstream& operator<<(ofstream& out, Produs& p)
	{
		out << p.tipProdus << " ";
		out << p.numeProdus << " ";
		out << p.pretProdus << " ";
		out << p.cantitate << " ";
		out << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Produs& p)
	{
		in >> p.tipProdus;
		in >> p.numeProdus;
		in >> p.pretProdus;
		in >> p.cantitate;
		return in;
	}

	const Produs operator=(const Produs& p )
	{
		if (this != &p)
		{
			this->tipProdus = p.tipProdus;
			this->numeProdus = p.numeProdus;
			this->pretProdus = p.pretProdus;
			this->cantitate = p.cantitate;

		}
		return *this;
	}

	void scrieCSV(ofstream& out)
	{
		out << this->tipProdus << ",";
		out << this->numeProdus << ",";
		out << this->pretProdus << ",";
		out << this->cantitate << ",";
		out << endl;
	}

};

class Mancare:public Produs
{
private:
	
	bool alergeni;
	int kcalorii;

public:

	Mancare():Produs()
	{
		alergeni = true;
		kcalorii = 355;
	}

	Mancare(CategorieProdus tip, string nume, int pret, int cantitate, bool alg, int kcal) :Produs(tip, nume, pret, cantitate)
	{
		this->alergeni = alg;
		this->kcalorii = kcal;
	}

	Mancare(const Mancare& m):Produs(m)
	{
		this->alergeni = m.alergeni;
		this->kcalorii = m.kcalorii;
	}

	Mancare& operator=(const Mancare& m)
	{
		Produs::operator=(m);
		this->alergeni = m.alergeni;
		this->kcalorii = m.kcalorii;
	}

	friend ostream& operator<<(ostream& o, const Mancare& m)
	{
		o <<" Alergeni: "<< m.alergeni << endl;
		o <<" Valoare energetica: "<< m.kcalorii << endl;
		o << (Produs)m << endl;
		return o;
	}
	
};



void main()
{
	system("Color 04");
	cout << "				RESTAURANT			" << endl<< "____________________________________________________________________________________" << endl << endl;

	//Mancare m;
	//cout << m;

	cout << "Tastati numarul pentru a accesa functia dorita:" << endl;

	list<string> meniu;
		meniu.push_back("	1--MESE: Inregistrare Date, Afisare Date, Incasari");
		meniu.push_back("	2--OSPATARI: Inregistrare Date, Afisare Date, Bonus");
		meniu.push_back("	3--BARMANI: Inregistrare Date, Afisare Date, Comision");
		meniu.push_back("	4--BUCATARI: Inregistrare Date, Afisare Date, Comision");
		meniu.push_back("	5--MARFA: Inregistrare Date, Afisare Date, Total Plata, TVA");
		meniu.push_back("	6--ANGAJATI: Arhiva-Afisare Date");
		meniu.push_back("	7--MENIU: Inregistrare Date, Afisare Date");
		meniu.push_back("	0--EXIT PROGRAM");

		for (list<string>::iterator it = meniu.begin(); it != meniu.end(); it++)
		{
			cout << *it<<endl;
		}
	

	int n;
	cin >> n;
	cin.get();
	while (n != 0 || n > 6)
	{
		if (n == 1)
		{
			Masa m1;
			Masa m2(3, true);
			//m2.afisareMasa();
			Masa m3(2, true, "Ionescu V", 3, new int[3]{ 123,44,500 }, 30);
			//m3.afisareMasa();
			cin >> m1;
			cout << m1;
			ofstream file("Mese.txt", ios::app);
			file << m1;
			file.close();
			ofstream fileOut("Mese.csv", ios::app);
			m1.scrieCSV(fileOut);
			fileOut.close();
			int suma = (int)m1;
			float conversie = (float)m1;
			cout << "Suma totala incasata este de: " << suma << "  RON |  " << conversie << "  EUR " << endl << endl;
		}

		if (n == 2)
		{
			Ospatar o1("Popescu Ion", 4500, 9, new int[9]{ 4,5,6,7,8,9,10,11,12 }, 8);
			//o1.afisareOspatar();
			Ospatar o2;
			cin >> o2;
			cout << o2;
			ofstream file("Ospatari.txt", ios::app);
			file << o2;
			file.close();
			ofstream fileOut("Ospatari.csv", ios::app);
			o2.scrieCSV(fileOut);
			fileOut.close();
			float bonus = (float)o2;
			cout << " Ospatarul are un bonus de " << bonus << " RON." << endl << endl;
		}

		if (n == 3)
		{
			Barman b1("Andrei Ionescu", 5500, true, 5, new int[5]{ 121,90,150,89,66 }, 8);
			//b1.afisareBarman();
			Barman b2;
			cin >> b2;
			cout << b2;
			ofstream file("Barmani.txt", ios::app);
			file << b2;
			file.close();
			ofstream fileOut("Barmani.csv", ios::app);
			b2.scrieCSV(fileOut);
			fileOut.close();
			int comisionT = (int)b2;
			cout << " Comisionul total acumulat in saptamana anterioara este de " << comisionT << " RON." << endl << endl;
		}
		
		if (n == 4)
		{
			Bucatar bu1("Zaharia Octavian", 5000, 3, new int[3]{ 123,32,55 }, 8);
			//bu1.afisareBucatar();
			Bucatar bu2;
			cin >> bu2;
			cout << bu2;
			ofstream file("Bucatari.txt", ios::app);
			file << bu2;
			file.close();
			ofstream fileOut("Bucatari.csv", ios::app);
			bu2.scrieCSV(fileOut);
			fileOut.close();
			int comisionBT = (int)bu2;
			cout<< " Comisionul total acumulat in saptamana anterioara este de " << comisionBT << " RON." << endl << endl;
		}

		if (n == 5)
		{
			Marfa ma1(0, bar, 4300, 3, new int[3]{ 2900,3222,5303 });
			//ma1.afisareMarfa();
			Marfa ma2;
			cin >> ma2;
			cout << ma2;
			ofstream file("Marfa.txt", ios::app);
			file << ma2;
			file.close();
			ofstream fileOut("Marfa.csv", ios::app);
			ma2.scrieCSV(fileOut);
			fileOut.close();
			int costT = (int)ma2;
			float tva = (float)ma2;
			cout << " In luna anterioara, s-a achizitionat marfa in valoare totala de " << costT << " RON, din care " << tva << " RON reprezinta TVA-ul" << endl;
		}

		if (n == 6)
		{
			cout << "					ARHIVA ANGAJATI			"<<endl;
			cout << " Lista cu toti angajatii/fostii angajati de la deschiderea restaurantului pana la inceputul anului curent: " << endl;
			
			Angajati arhiva(1, new Barman* [1]{ new Barman() }, 1, new Ospatar* [1]{ new Ospatar() }, 1, new Bucatar* [1]{ new Bucatar() });
			
			for (int i = 0; i < arhiva.getNrBarmani(); i++)
				arhiva.getBarmani()[i]->afiseazaDescriere();

			for (int i = 0; i < arhiva.getNrOspatari(); i++)
				arhiva.getOspatari()[i]->afiseazaDescriere();

			for (int i = 0; i < arhiva.getNrBucatari(); i++)
				arhiva.getBucatari()[i]->afiseazaDescriere();
		}

		if (n == 7)
		{
			cout << "					MENIU		" << endl;
			cout << "Introduceti numarul de produse pe care doriti sa le inregistrati: ";
			int nrp;
			cin >> nrp;
			cin.get();
			Produs* p=new Produs[nrp];
			vector<Produs> meniu;
			
			for (int i = 0; i < nrp; i++)
			{
				cin >> p[i];
				meniu.push_back(p[i]);
				
			}

			for (int i = 0; i < meniu.size(); i++)
			{
				cout << meniu[i] << endl;
			}

			ofstream file("Meniu.txt", ios::app);
			for (int i = 0; i < meniu.size(); i++)
			{
				file << meniu[i];
			}
			file.close();
			
			ofstream fileOut("Meniu.csv", ios::app);
			for (int i = 0; i < meniu.size(); i++)
			{
				meniu[i].scrieCSV(fileOut);
			}
			fileOut.close();
		}
		
		cout << "Tastati numarul pentru a accesa functia dorita: " << endl;
		int p;
		cin >> p;
		n = p;
		cin.get();
	}
}