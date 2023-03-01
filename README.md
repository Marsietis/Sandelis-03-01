# Sandelis-03-01
Sandelio valdymo programa

Philosophy behind program:

Make program work well and keep code tidy -- (Hell no),
Make programs console ui pretty -- (absolutely)

Pasirinkus sandelio ismatavimus galima ivesti kiek norite deziu is 4 standartiniu deziu pasirinkimu.
Deziu dydziai:
box1 = 2x2x2
box2 = 2x1x2
box3 = 1x1x1
box4 = 2x1.5x1.5
Programa patikrina ar sandelyje yra vietos. Jei dezes telpa, jos yra patalpinamos i sandely, jei ne - perspeja kad dezes netelpa sandelyje.
Programa gali isvesti deziu, esanciu sandelyje, sarasa, bei sandelyje likusia vieta.


Naudojimas:
  Pasirinkite sandelio dydi.
    Galima pasirinkti is dvieju skirtingu sandelio ismatavimu.
  
 # Pagrindinis meniu:
 
    [1] Prideti deziu
    # Ivedama kiek ir kokiu ismatavimo deziu norima prideti i sandeli. Jei dezes telpa, jos yra patalpinamos i sandely, jei ne - perspeja kad dezes netelpa sandelyje.
    
    [2] Sandelyje esanciu deziu sarasas
    # isvedamas visas bendras sandelyje esasnciu deziu sarasas, bei kiekvieno ismatavimo deziu atskiras kiekis.
    
    [3] Sandelyje likusi vieta
    # Isvedamas kiekvienos eiles laisvas like turis kubiniais metrais.
    
    [4] Baigti programos darba
    # Baigimas programos darbas.
    
# Programos veikimas:
  Pagrindines programos veikimo funkcijos:

    int main()
    void WarehouseChoice();
    void Menu();
    void BoxList();
    void SpaceRemaining();
    
    int main()
    # Ivedami sandelio ismatavimai (zr. void WarehouseChoice();)
    
    # Apskaiciuojama kiek eiliu yra sandelyje
     size = length / (rowLength + rowGap);
     
    # Apskaiciuojamas vienos eiles bei bendras sandelio turis
     int rowVolume = (rowLength * width * height);
     int totalSpace = size * rowVolume;
     
    # Kiekvienam eiles masyvo elementui yra priskiriamas eiles turis
      for (int i = 0; i < size; i++)
        {
          rows[i] = rowVolume;
        }
        
    # Parodomas meniu (zr. void Menu();)
    
    # Tikrinamas vartotojo pasirinkimas
    
    # [1] --
    
    # Tikrinama ar sandelis yra pilnai uzpildytas, jei taip nebeleidzia testi deziu pridejimo ir grazina i pagrindini meniu:
       if (totalSpace == 0)
       
    # Ivedamas kiekvienos dezes kiekis
    
    # Apskaiciuojamas visas turis kuri uzima ivestos dezes
      formule -- kiekvienos dezes turis * ivestas kiekis
                  visu tipu deziu bendras turis yra sudedamas
                  viskas irasoma totalVolume kintamajyje
                  
    # Tikrinama ar sandelyje yra pakankamai vietos
      if (totalVolume > (rowVolume * size) || totalVolume > totalSpace)
      
    # Jei vietos pakanka:
     Apskaiciuojama likusi vieta sandelyje
                totalSpace = totalSpace - totalVolume;
                
    # Pagrinidnis deziu pridejimo loopas:
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
    
      void WarehouseChoice();
      # Pagal vartotojo pasirinkima yra nustatomas sandelio ilgis ir plotis.
      
      void Menu();
      # Pagrindinis programos meniu
        cout << "----Pasirinkite norima funkcija:----" << endl;
        cout << "    [1] Prideti deziu" << endl;
        cout << "    [2] Sandelyje esanciu deziu sarasas" << endl;
        cout << "    [3] Sandelyje likusi vieta" << endl;
        cout << "    [4] Baigti programos darba" << endl;
      
      void BoxList();
      # Isvedamas sandelyje esanciu deziu sarasas
        Veikimas:
          # Parodo vartotojo ivesta kiekvienos dezes kieki.
         
      void SpaceRemaining();
      # Isvedama vieta likusi kiekvienoje eileje
        Veikimas:
          # for loop, kuriame kiekviena karta isvedamas likes turis tame masyvo elemente
              for (int i = 0; i < size; i++) //size -- eiliu kiekis sandelyje, apskaiciuojmas pagal formule size = length / (rowLength + rowGap);
                {
                   cout << "Eileje " << i + 1 << " liko vietos: " << rows[i] << endl;
                }
        
    
    
    
