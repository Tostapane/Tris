#include <iostream>

using namespace std;
/*
 Posizioni: (x,y)

       (0,0)   |   (1,0)     |    (2,0)
---------------------------------------------
       (0,1)   |   (1,1)     |    (2,1)
---------------------------------------------
       (0,2)   |   (1,2)     |    (2,2)
 */
int inserisci(int cont)
{
    int input;
    //scelta input
    if (cont % 2 == 0)
    {
        input = 1;
    }
    else
    {
        input = 0;
    }
    return input;
}

int posi()
{
    int k;
    do
    {
        cin >> k;
        if (k < 0 || k > 2)
        {
            cout << "Deve essere compreso tra 0 e 2" << endl;
        }
    } while (k < 0 || k > 2);
    return k;
}

void stampa(int mat[][3])
{
    int riga;
    int colonna;
    for (riga = 0; riga < 3; riga++)
    {
        if (riga > 0)
        {
            cout << " ";
        }
        for (colonna = 0; colonna < 3; colonna++)
        {
            if (colonna == 1)
            {
                cout << "|" << "   ";
                if (mat[colonna][riga] == 2)
                {
                    cout << " ";
                }
                else
                {
                    cout << mat[colonna][riga];
                }
                cout << "    " << "|";
            }
            else
            {
                cout << "    ";
                if (mat[colonna][riga] == 2)
                {
                    cout << " ";
                }
                else
                {
                    cout << mat[colonna][riga];
                }
                cout << "    ";
            }
        }
        if (riga < 2)
        {
            cout << endl << "------------------------------" << endl;
        }
        else
        {
            cout << endl;
        }
    }
}

int controllo( int mat[][3])
{
    int contUno, contDue = 0;
    int verifica = 0;

    //controllo verticale
    for (contUno = 0; contUno < 3; contUno++)
    {
            if (mat[contUno][contDue] == mat[contUno][contDue + 1] && mat[contUno][contDue + 1] == mat[contUno][contDue + 2] && mat[contUno][contDue] != 2)
            {
                verifica++;
                cout << "Partita finita, vince il: " << mat[contUno][contDue] << "per via del controllo verticale";
                break;
            }
    }
    //controllo orizzontale
    contUno = 0;
    for (contDue = 0; contDue < 3; contDue++)
    {
        if (mat[contUno][contDue] == mat[contUno + 1][contDue] && mat[contUno + 1][contDue] == mat[contUno + 2][contDue] && mat[contUno][contDue] != 2)
        {
            verifica++;
            cout << "Partita finita, vince il: " << mat[contUno][contDue] << "per via del controllo orizzontale";
            break;
        }
    }

    //controllo diagonale sinistra
    if (mat[contUno][contDue] == mat[contUno + 1][contDue + 1] && mat[contUno + 1][contDue + 1] == mat[contUno + 2][contDue + 2] && mat[contUno][contDue] != 2)
    {
        verifica++;
        cout << "Partita finita, vince il: " << mat[contUno][contDue] << "per via del controllo diagonale 1";
    }
    //controllo diagonale destra
    contUno = 2;
    contDue = 2;
    if (mat[contUno][contDue] == mat[contUno - 1][contDue - 1] && mat[contUno - 1][contDue - 1] == mat[contUno - 2][contDue - 2] && mat[contUno][contDue] != 2)
    {
        verifica++;
        cout << "Partita finita, vince il: " << mat[contUno][contDue] << "per via del controllo diagonale 2";
    }
    return verifica;
}



    int main()
    {
        int tris[3][3];
        int posx;
        int posy;
        int scelta;
        int contUno;
        int contDue;
        int verifica;

        for (contUno = 0; contUno < 3; contUno++)
        {
            for (contDue = 0; contDue < 3; contDue++)
            {
                tris[contDue][contUno] = 2;
            }
        }

        for (contUno = 0; contUno < 9; contUno++)
        {
            do
            {
                cout << "Inserisci posizione x: ";
                posx = posi();
                cout << "Inserisci posizione y: ";
                posy = posi();
                if (tris[posx][posy] != 2)
                {
                    cout << "Non puoi inserire un numero in questa casella perche' e' gia' stata selezionata" << endl;
                }
            } while (tris[posx][posy] != 2);
            scelta = inserisci(contUno);
            tris[posx][posy] = scelta;
            stampa(tris);
            verifica = controllo(tris);
            if (verifica > 0)
            {
                break;
            }
        }
        if (verifica == 0)
        {
            cout << "Non ha vinto nessuno" << endl;
        }
        return 0;
    }


