#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;

void Title();
void WarehouseChoice(int &length, int &width);
void Menu();
void BoxList(int box1Kiek, int box2Kiek, int box3Kiek, int box4Kiek);
void SpaceRemaining(int rows[], int size);

int main()
{
    Title();
    int length;
    int width;
    int height = 6;

    // Sandelio dydzio pasirinkimas
    WarehouseChoice(length, width);
    system("cls");

    int rowLength = 2;
    int rowGap = 2;

    // Apskaiciuojama kiek eiliu yra sandelyje
    int size = 0;
    size = length / (rowLength + rowGap);

    // Apskaiciuojamas vienos eiles turis
    int rowVolume = (rowLength * width * height);

    // Apskaiciuojamas bendras sandelio turis kuriame galima talpinti dezes
    int totalSpace = size * rowVolume;

    // Kiekvienam eiles masyvo elementui yra priskiriamas eiles turis
    int rows[size];
    for (int i = 0; i < size; i++)
    {
        rows[i] = rowVolume;
    }

    // Deziu turiai
    // 2x2x2
    double box1 = 8;
    // 2x1x2
    double box2 = 4;
    // 1x1x1
    double box3 = 1;
    // 2x1.5x1.5
    double box4 = 4.5;

    // Deziu kiekiai
    int box1Kiek, box2Kiek, box3Kiek, box4Kiek = 0;
    int box1Temp, box2Temp, box3Temp, box4Temp = 0;

Title();
    // Programos pradzia
    int choise = 0;
    while (choise != 4)
    {
        Menu();

        cin >> choise;
        system("cls");
        // tikrinama ar ivestas tinkamas pasirinkimas
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Netinkamas pasirinkimas" << endl;
            continue;
        }

        // Prideti deziu
        if (choise == 1)
        {
            // Jei sandelyje nera vietos, tai neleidziama prideti deziu
            if (totalSpace == 0)
            {
                cout << "Sandelis uzpildytas" << endl;
                continue;
            }

            cout << "Iveskite kiek norite prideti 2x2x2 deziu:" << endl;
            cin >> box1Temp;
            if (box1Kiek < 0)
            {
                cout << "Kiekis negali buti neigiamas" << endl;
                continue;
            }

            cout << "Iveskite kiek norite prideti 2x1x2 deziu:" << endl;
            cin >> box2Temp;
            if (box2Kiek < 0)
            {
                cout << "Kiekis negali buti neigiamas" << endl;
                continue;
            }

            cout << "Iveskite kiek norite prideti 1x1x1 deziu:" << endl;
            cin >> box3Temp;
            if (box3Kiek < 0)
            {
                cout << "Kiekis negali buti neigiamas" << endl;
                continue;
            }

            cout << "Iveskite kiek norite prideti 2x1.5x1.5 deziu:" << endl;
            cin >> box4Temp;
            if (box4Kiek < 0)
            {
                cout << "Kiekis negali buti neigiamas" << endl;
                continue;
            }

            system("cls");

            // Apskaiciuojamas bendras deziu turis
            double box1Volume = box1 * box1Temp;
            double box2Volume = box2 * box2Temp;
            double box3Volume = box3 * box3Temp;
            double box4Volume = box4 * box4Temp;
            double totalVolume = box1Volume + box2Volume + box3Volume + box4Volume;

            // Tikrinama ar sandelyje yra pakankamai vietos
            if (totalVolume > (rowVolume * size) || totalVolume > totalSpace)
            {
                cout << "Sandelyje nepakanka vietos" << endl;
                continue;
            }

            else
            {
                // Apskaiciuojama likusi vieta sandelyje
                totalSpace = totalSpace - totalVolume;

                box1Kiek += box1Temp;
                box2Kiek += box2Temp;
                box3Kiek += box3Temp;
                box4Kiek += box4Temp;

                int i = 0;
                while (totalVolume > 0)
                {
                    if (rows[i] >= totalVolume)
                    {
                        rows[i] = rows[i] - totalVolume;
                        totalVolume = 0;
                        // break;
                    }
                    else
                    {
                        totalVolume = totalVolume - rows[i];
                        rows[i] = 0;
                    }
                    i++;
                }

                cout<<"Dezes sekmingai patalpintos sandelyje"<<endl;
                SpaceRemaining(rows, size);
            }
        }

        // Sandelyje esanciu deziu sarasas
        else if (choise == 2)
        {
            BoxList(box1Kiek, box2Kiek, box3Kiek, box4Kiek);
        }

        // Likusi vieta
        else if (choise == 3)
        {
            SpaceRemaining(rows, size);
        }

        // baigiamas programos darbas
        else if (choise == 4)
        {
            cout << "Baigimas programos darbas" << endl;
        }

        // Jei ivestas netinkamas pasirinkimas
        else
        {
            cout << "Netinkamas pasirinkimas" << endl;
        }
    }
}

void Menu()
{
    cout << "                                    " << endl;
    cout << "----Pasirinkite norima funkcija:----" << endl;
    cout << "    [1] Prideti deziu" << endl;
    cout << "    [2] Sandelyje esanciu deziu sarasas" << endl;
    cout << "    [3] Sandelyje likusi vieta" << endl;
    cout << "    [4] Baigti programos darba" << endl;
}

// Isvedamas sandelyje esanciu deziu sarasas
void BoxList(int box1Kiek, int box2Kiek, int box3Kiek, int box4Kiek)
{
    cout << "Sandelyje esanciu deziu sarasas:" << endl;
    cout << "Viso deziu: " << box1Kiek + box2Kiek + box3Kiek + box4Kiek << endl;
    cout << "2x2x2 deziu: " << box1Kiek << endl;
    cout << "2x1x2 deziu: " << box2Kiek << endl;
    cout << "1x1x1 deziu: " << box3Kiek << endl;
    cout << "1x1x1 deziu: " << box4Kiek << endl;
}

// Isvedama likusi kiekvienoje eileje
void SpaceRemaining(int rows[], int size)
{
    cout << "Sandelyje likusi vieta (kubiniais metrais):" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Eileje " << i + 1 << " liko vietos: " << rows[i] << endl;
    }
}

void WarehouseChoice(int &length, int &width)
{
    cout << "Pasirinkite sandelio dydi:" << endl;
    cout << "[1] 50x25" << endl;
    cout << "[2] 75x20" << endl;
    int choiceWarehouse;
    cin >> choiceWarehouse;
    if (choiceWarehouse == 1)
    {
        length = 50;
        width = 25;
    }
    else if (choiceWarehouse == 2)
    {
        length = 75;
        width = 20;
    }
    else
    {
        cout << "Netinkamas pasirinkimas" << endl;
        WarehouseChoice(length, width);
    }
}

void Title()
{

    cout << R"(       _____                 _      _ _         _____  _____  )" << endl;
    cout << R"(      / ____|               | |    | (_)       |_   _|/ ____| )" << endl;
    cout << R"(     | (___   __ _ _ __   __| | ___| |_  ___     | | | (___   )" << endl;
    cout << R"(      \___ \ / _` | '_ \ / _` |/ _ \ | |/ _ \    | |  \___ \    )" << endl;
    cout << R"(      ____) | (_| | | | | (_| |  __/ | | (_) |  _| |_ ____) | )" << endl;
    cout << R"(     |_____/ \__,_|_| |_|\__,_|\___|_|_|\___/  |_____|_____/    )" << endl;
    cout << "" << endl;
}

// 2023 Martynas Matijosius