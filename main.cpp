#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

typedef struct Student
{
    string name;
    string surname;
    string faculty;
    float avgScore;
    int age;
} Student;

Student setStruct(string name, string surname, string faculty, float avgScore, int age)
{
    Student s;
    s.name = name;
    s.surname = surname;
    s.faculty = faculty;
    s.age = age;
    s.avgScore = avgScore;
    return s;
}

void printVectorStruct(vector<Student>v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        cout << setw(12) << v[i].name << setw(12) << v[i].surname << setw(9) << v[i].faculty
             << setw(14) << v[i].age << setw(9) << v[i].avgScore << endl;
    }
}



void linearNameSearch(vector<Student>v, vector<int>&index, string name)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].name.compare(name) == 0)
            index.push_back(i);
    }
}

void linearAgeSearch(vector<Student>v, vector<int>&index, int age)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].age == age)
            index.push_back(i);
    }
}

void selectionSort(vector<Student>& arr)
{
    int min_ind;

    for (int i = 0; i < arr.size() - 1; ++i)
    {
        min_ind = i;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j].name.compare(arr[min_ind].name) < 0)
                min_ind = j;
        }

        if (min_ind != i)
            swap(arr[min_ind], arr[i]);
    }
}

int binaryNameSearch(vector<Student>&v, string key, int left, int right)
{

    while (left <= right)
    {
        int middleElement = left + (right - left) / 2;

        if (v[middleElement].name.compare(key) == 0)
        {
            return middleElement;
        }

        if (v[middleElement].name.compare(key) < 0)
        {
            left = middleElement + 1;
        }

        else
        {
            right = middleElement - 1;
        }
    }
    return -1;
}








int main()
{
    vector<Student>v;
    vector<int>corres;
    int stop = 1;
    v.push_back(setStruct("Denys", "Mikucionys", "IS", 7.6, 20));
    v.push_back(setStruct("Renat", "Furs", "INF", 7.2, 19));
    v.push_back(setStruct("Renat", "Furs", "PS", 11, 99));
    v.push_back(setStruct("Dominykas", "Kozlovskis", "INF", 8.2, 19));
    v.push_back(setStruct("Nikita", "Kuznecov", "TL", 8, 19));

    cout << setw(12) << "Name:" << setw(12) << "Surname:" << setw(12) << "Faculty:"
         << setw(12) << "Age:" << setw(12) << "avgScore:" << endl;
    cout << "---------------------------------------------------------" << endl;
    printVectorStruct(v);

    while (stop != 0)
    {
        cout << "-------------MENIU------------------------" << endl;
        cout << "1. Search by key word using linear searching. (all correspondences)." << endl;
        cout << "2. Search by key word using binary searching. (1 correspondence)" << endl;
        cout << "3. Search by age  using linear searching. (all correspondence)" << endl;
        cout << "0. Exit the program. " << endl;
        cout << "-------------------------------------" << endl;
        cout << "Choose an option: ";
        cin >> stop;
        cout << "-------------------------------------" << endl;

        switch (stop)
        {
            case 1:
            {
                string key;
                cout << "Enter the name you want to find" << endl;
                cin >> key;

                linearNameSearch(v, corres, key);


                if (corres.size() == 0)
                    cout << "There is no correspondences" << endl;

                else
                {
                    for (int i = 0; i < corres.size(); ++i)
                    {
                        cout << i + 1 << ". " << setw(12) << v[corres[i]].name << setw(12) << v[corres[i]].surname << setw(9) << v[corres[i]].faculty
                             << setw(14) << v[corres[i]].age << setw(9) << v[corres[i]].avgScore << endl;
                    }

                }
                stop = 0;
                break;

            }

            case 2:
            {
                string key;
                cout << "Enter the name you want to find" << endl;
                cin >> key;
                selectionSort(v);
                int ind = binaryNameSearch(v, key, 0, v.size());

                if(ind == -1)
                    cout << "There is no correspondences" << endl;

                else
                {
                    cout << setw(12) << v[ind].name << setw(12) << v[ind].surname << setw(9) << v[ind].faculty
                         << setw(14) << v[ind].age << setw(9) << v[ind].avgScore << endl;
                }
                stop = 0;
                break;
            }
            case 3:
            {
                int n_key;
                string key;
                cout << "Enter the age you want to find" << endl;
                cin >> key;
                n_key = stoi(key);

                linearAgeSearch(v, corres, n_key);


                if (corres.size() == 0)
                    cout << "There is no correspondences" << endl;

                else
                {
                    for (int i = 0; i < corres.size(); ++i)
                    {
                        cout << i + 1 << ". " << setw(12) << v[corres[i]].name << setw(12) << v[corres[i]].surname << setw(9) << v[corres[i]].faculty
                             << setw(14) << v[corres[i]].age << setw(9) << v[corres[i]].avgScore << endl;
                    }

                }
                stop = 0;
                break;

            }
        }
    }

    /*linearNameSearch(v, corres, "Renat");
    selectionSort(v);
    int ind = binaryNameSearch(v, "Renat", true, 0, v.size());
    cout << setw(12) << v[ind].name << setw(12) << v[ind].surname << setw(9) << v[ind].faculty
        << setw(14) << v[ind].age << setw(9) << v[ind].avgScore << endl;*/





    return 0;
}
