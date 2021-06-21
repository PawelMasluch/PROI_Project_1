// Pawel Masluch
#include<iostream>
#include<string>
#include<vector>


using namespace std;


//#define _DEBUG // jesli wykomentujemy te linie, nie mamy trybu _DEBUG, i na odwrot


class Client
{
	private:
		string PESEL; // nr PESEL
		string name; // imie
		string surname; // nazwisko
		
	public:
		
		Client(string pesel="00000000000", string n="Jan", string s="Kowalski") // konstruktor
		{
			PESEL = pesel;
			name = n;
			surname = s;
			
			#ifdef _DEBUG
				cout << "\nUtworzono nowego klienta (obiekt klasy Client)\n";
			#endif
		}
		
		~Client(){} // destruktor
		
		Client(const Client &x) // konstruktor kopiujacy
		{
			PESEL = x.PESEL;
			name = x.name;
			surname = x.surname;
			#ifdef _DEBUG
				cout << "\nSkopiowano obiekt typu Client\n";
			#endif
	    }
		
		bool operator ==(Client &x)
		{
			return ( (*this).PESEL == x.PESEL  &&  (*this).name == x.name  &&  (*this).surname == x.surname );
		} 
		
		void input() // wczytaj dane do obiektu
		{
			cout << "\nPodaje dane klienta\nPodaj PESEL: ";
			cin >> PESEL;
			cout << "Podaj imie: ";
			cin >> name;
			cout << "Podaj nazwisko: ";
			cin >> surname;
			cout << "\n";
		}
		
		void output() // wypisz dane o obiekcie
		{
			cout << "\nWypisuje dane klienta\nPESEL: " << PESEL << "\nImie: " << name << "\nNazwisko: " << surname << "\n";
		}
};




class Instructor
{
	private:
		string PESEL; // nr PESEL
		string name; // imie
		string surname; // nazwisko
		
	public:
		
		Instructor(string pesel="00000000000", string n="Jan", string s="Kowalski") // konstruktor
		{
			PESEL = pesel;
			name = n;
			surname = s;
			
			#ifdef _DEBUG
				cout << "\nUtworzono nowego instruktora (obiekt klasy Instructor)\n";
			#endif
		}
		
		~Instructor(){} // destruktor
		
		Instructor(const Instructor &x) // konstruktor kopiujacy
		{
			PESEL = x.PESEL;
			name = x.name;
			surname = x.surname;
			
			#ifdef _DEBUG
				cout << "\nSkopiowano obiekt typu Instructor\n";
			#endif
	    }
		
		bool operator ==(Instructor &x)
		{
			return ( (*this).PESEL == x.PESEL  &&  (*this).name == x.name  &&  (*this).surname == x.surname );
		} 
		
		void input() // wczytaj dane do obiektu
		{
			cout << "\nPodaje dane instruktora\nPodaj PESEL: ";
			cin >> PESEL;
			cout << "Podaj imie: ";
			cin >> name;
			cout << "Podaj nazwisko: ";
			cin >> surname;
			cout << "\n";
		}
		
		void output() // wypisz dane o obiekcie
		{
			cout << "\nWypisuje dane instruktora\nPESEL: " << PESEL << "\nImie: " << name << "\nNazwisko: " << surname << "\n";
		}
};




class Equipment
{
	private:
		int size; // rozmiar
		string color; // kolor
		string manufacturer; // producent
		
	public:
		
		Equipment(int s=0, string c="brak", string m="brak") // konstruktor
		{
			size = s;
			color = c;
			manufacturer = m;
			
			#ifdef _DEBUG
				cout << "\nUtworzono nowy sprzet (obiekt klasy Equipment)\n";
			#endif
		}
		
		~Equipment(){} // destruktor
		
		Equipment(const Equipment &x) // konstruktor kopiujacy
		{
			size = x.size;
			color = x.color;
			manufacturer = x.manufacturer;
			
			#ifdef _DEBUG
				cout << "\nSkopiowano obiekt typu Equipment\n";
			#endif
	    }
		
		bool operator ==(Equipment &x)
		{
			return ( (*this).size == x.size  &&  (*this).color == x.color  &&  (*this).manufacturer == x.manufacturer );
		}
		
		void input() // wczytaj dane do obiektu
		{
			cout << "\nPodaje dane sprzetu\nPodaj rozmiar: ";
			cin >> size;
			cout << "Podaj kolor: ";
			cin >> color;
			cout << "Podaj producenta: ";
			cin >> manufacturer;
			cout << "\n";
		}
		
		void output() // wypisz dane o obiekcie
		{
			cout << "\nWypisuje dane sprzetu\nRozmiar: " << size << "\nKolor: " << color << "\nProducent: " << manufacturer << "\n";
		}
};





class SkiSchool // szkola narciarska
{
	private:
		string location; // miejscowosc, w ktorej miesci sie siedziba szkoly
		int established; // rok powstania szkoly
		Instructor x; // instruktor
		
		int NumberOfClients; // liczba klientow
		vector < Client > ClientsList; // lista klientow
		
		int NumberOfInstructors; // liczba instruktorow
		vector < Instructor > InstructorsList; // lista instruktorow
		
		int NumberOfEquipment; // liczba sprzetu
		vector < Equipment > EquipmentList; // lista sprzetu
		
	
	public:
		
		SkiSchool(string l, int e, Instructor xx) // konstruktor
		{
			location = l;
			established = e;
			NumberOfClients = 0;
			x = xx;
			NumberOfInstructors = 1;
			InstructorsList.push_back(xx);
			NumberOfEquipment = 0;
			
			#ifdef _DEBUG
				cout << "\nUtworzono nowa szkole (obiekt typu SkiSchool)\n";
			#endif
		}
		
		~SkiSchool(){} // destruktor
		
		SkiSchool(const SkiSchool &S) // konstruktor kopiujacy
		{
			(*this).location = S.location;
			(*this).established = S.established;
			(*this).x = S.x;
			(*this).NumberOfClients = S.NumberOfClients;
			(*this).NumberOfInstructors = S.NumberOfInstructors;
			(*this).NumberOfEquipment = S.NumberOfEquipment;
			
			(*this).ClientsList.clear();
			for(int i=0; i<S.NumberOfClients; ++i)
			{
				(*this).ClientsList.push_back( S.ClientsList[i] );
			}
			
			(*this).InstructorsList.clear();
			for(int i=0; i<S.NumberOfInstructors; ++i)
			{
				(*this).InstructorsList.push_back( S.InstructorsList[i] );
			}
			
			(*this).EquipmentList.clear();
			for(int i=0; i<S.NumberOfEquipment; ++i)
			{
				(*this).EquipmentList.push_back( S.EquipmentList[i] );
			}
			
			#ifdef _DEBUG
				cout << "\nSkopiowano obiekt typu SkiSchool\n";
			#endif
	    }
		
		
		SkiSchool operator +=(Client &x) // dodaj klienta do szkoly
		{
			++NumberOfClients;
			ClientsList.push_back(x);
			#ifdef _DEBUG
				printf( "\nDodano klienta do szkoly\n" );
			#endif
			return *this;
		}
		
		SkiSchool operator -=(Client &x) // usun klienta ze szkoly
		{
			bool deleted = false; // jak na razie nie usunieto klienta
			
			for(vector <Client>:: iterator it=ClientsList.begin(); it!=ClientsList.end() && deleted==false; ++it)
			{
				if( (*it) == x )
				{
					swap( (*it), ClientsList.back() );
					ClientsList.pop_back();
					--NumberOfClients;
					deleted = true;
					#ifdef _DEBUG
						printf( "\nUsunieto klienta ze szkoly\n" );
					#endif
				}
			}
			
			if(deleted == false)
			{
				#ifdef _DEBUG
					printf( "\nNie udalo sie usunac klienta ze szkoly\n" );
				#endif
			}
			
			return *this;
		}
		
		
		SkiSchool operator +=(Instructor &x) // dodaj instruktora do szkoly
		{
			++NumberOfInstructors;
			InstructorsList.push_back(x);
			#ifdef _DEBUG
				cout << "\nDodano instruktora do szkoly\n";
			#endif
			return *this;
		}
		
		SkiSchool operator -=(Instructor &x)// usun instruktora ze szkoly
		{
			bool deleted = false; // jak na razie nie usunieto instruktora
			
			for(vector <Instructor>:: iterator it=InstructorsList.begin(); it!=InstructorsList.end() && deleted==false; ++it)
			{
				if( (*it) == x )
				{
					swap( (*it), InstructorsList.back() );
					InstructorsList.pop_back();
					--NumberOfInstructors;
					deleted = true;
					#ifdef _DEBUG
						printf( "\nUsunieto instruktora ze szkoly\n" );
					#endif
				}
			}
			
			if(deleted == false)
			{
				#ifdef _DEBUG
					printf( "\nNie udalo sie usunac instruktora ze szkoly\n" );
				#endif
			}
			
			return *this;
		}
		
		
		SkiSchool operator +=(Equipment &x) // dodaj sprzet do szkoly
		{
			++NumberOfEquipment;
			EquipmentList.push_back(x);
			#ifdef _DEBUG
				printf( "\nDodano sprzet do szkoly\n" );
			#endif
			return *this;
		}
		
		SkiSchool operator -=(Equipment &x) // usun sprzet ze szkoly
		{
			bool deleted = false; // jak na razie nie usunieto sprzetu
			
			for(vector <Equipment>:: iterator it=EquipmentList.begin(); it!=EquipmentList.end() && deleted==false; ++it)
			{
				if( (*it) == x )
				{
					swap( (*it), EquipmentList.back() );
					EquipmentList.pop_back();
					--NumberOfEquipment;
					deleted = true;
					#ifdef _DEBUG
						printf( "\nUsunieto sprzet ze szkoly\n" );
					#endif
				}
			}
			
			if(deleted == false)
			{
				#ifdef _DEBUG
					printf( "\nNie udalo sie usunac sprzetu ze szkoly\n" );
				#endif
			}
			
			return *this;
		}
		
		
		void output()
		{
			cout << "\n\nWypisuje dane o szkole\n";
			cout << "Lokalizacja: " << location << "\n";
			cout << "Rok powstania: " << established << "\n";
			cout << "Instruktor:\n";
			x.output();
			
			cout << "\nLiczba klientow: " << NumberOfClients << "\n";
			for(vector <Client>:: iterator it=ClientsList.begin(); it!=ClientsList.end(); ++it )
			{
				(*it).output();
			}
			
			cout << "\n\nLiczba instruktorow: " << NumberOfInstructors << "\n";
			for(vector <Instructor>:: iterator it=InstructorsList.begin(); it!=InstructorsList.end(); ++it )
			{
				(*it).output();
			}
			
			cout << "\n\nLiczba sprzetu: " << NumberOfEquipment << "\n";
			for(vector <Equipment>:: iterator it=EquipmentList.begin(); it!=EquipmentList.end(); ++it )
			{
				(*it).output();
			}
		}
};




void Simulate() // symuluj (wedlug ustalonego scenariusza) dzialanie szkoly narciarskiej
{
	// Zmienna automatyczna dla klasy SkiSchool
	cout << "Podaje automatycznego instruktora:\n";
	Instructor i1;
	i1.input();
	
	cout <<"\nTworzymy nowa szkole w ramach symulacji\n";
	SkiSchool s1("Zakopane",1997,i1); // wprowadzenie danych
	
	s1.output(); // wypisanie danych o szkole
	
	
	// dodawanie/usuwanie klientow ze szkoly
	Client c1;
	c1.input();
	
	s1 += c1;
	
	Client c2;
	c2.input();
	
	s1 -= c2;
	s1 += c2; 
	
	s1.output();
	
	
	cout << "\n\n\n\n\n\n";
	
	
	
	
	// dodawanie/usuwanie instruktora ze szkoly
	
	Instructor i2;
	i2.input();
	
	s1 -= i2;
	s1 += i2; 
	
	s1.output();
	
	
	
	cout << "\n\n\n\n\n\n";
	
	
	
	
	// dodawanie/usuwanie sprzetu ze szkoly
	
	Equipment e1;
	e1.input();
	
	s1 -= e1;
	s1 += e1; 
	
	s1.output();
	
	
	
	cout <<"\n\n\n\n\n\n";
	
	
	
	// kopiowanie danych o szkole do innej szkoly
	
	cout << "\nTworymy teraz w symulacji kolejna szkole\n";
	SkiSchool s2 = s1;
	s2.output();
}





int main()
{
	Simulate(); // symuluj (wedlug ustalonego scenariusza) dzialanie szkoly narciarskiej
	
	return 0;
}
