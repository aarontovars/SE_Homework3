#include <iostream>

using namespace std;

class ZooAnimal
{
 private:
   char *name;
   int cageNumber;
   int weightDate;
   int weight;
   ZooAnimal *mother;
 public:
   void Create (char*, int, int, int); // create function
   void Destroy (); // destroy function
   char* reptName ();
   inline int reptWeightDate () {return weightDate;};
   int daysSinceLastWeighed (int today);
   inline void changeWeightDate (int today) {weightDate=today;};
   void isMotherOf (ZooAnimal& mother_inp) {mother = &mother_inp;};
   char* reptMotherName();  // Additional function to get the mother's name
};

void ZooAnimal::Create(char *inp_name, int inp_cn, int inp_wd, int inp_w)
{
    name = inp_name;
    cageNumber = inp_cn;
    weightDate = inp_wd;
    weight = inp_w;
}

void ZooAnimal::Destroy ()
{
 delete [] name;
}

// -------- member function to return the animal's name
char* ZooAnimal::reptName ()
{
 return name;
}

// -------- member function to return the number of days
// -------- since the animal was last weighed
int ZooAnimal::daysSinceLastWeighed (int today)
{
 int startday, thisday;
 thisday = today/100*30 + today - today/100*100;
 startday = weightDate/100*30 + weightDate - weightDate/100*100;
 if (thisday < startday)
     thisday += 360;
 return (thisday-startday);
}

// -------- member function to return the name of the mother
char* ZooAnimal::reptMotherName()
{
    return mother->reptName();
}

int main()
{
    ZooAnimal bozo, mother_bozo;

    bozo.Create ((char*)"Bozo", 408, 1027, 400);
    mother_bozo.Create((char*)"Jackie", 203, 1026, 2862);
    bozo.isMotherOf(mother_bozo);

    cout << "This animal's name is " << bozo.reptName() << endl;
    cout << "The weight date is " << bozo.reptWeightDate() << endl;

    int today = 1037;
    bozo.changeWeightDate(today);

    cout << "The updated weight date is " << bozo.reptWeightDate() << endl;
    cout << "Bozo's mother is: " << bozo.reptMotherName() << endl;

    bozo.Destroy ();

    return 0;
}
