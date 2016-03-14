#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
    FILE *f = fopen("no.txt","r");
    FILE *y = fopen("yes.txt","r");
    char records[256][64];
    char yes[4098][64];

    int i = 0;
    int n = 0;
    int yi = 0;
    int cc = 0;

    if(f == NULL) cout << "ERROR: Could not open file no.txt" << endl;
    else
    {
        if(y == NULL) cout << "ERROR: Could not open file yes.txt" << endl;
        else
        {
            printf("             -------------------------------------\r\n");
            printf("             |           PROGRAM CHECK           |\r\n");
            printf("             |                                   |\r\n");


            do //Read from yes.txt
            {
                fgets(yes[yi],60,y);
                yi++;
            }
            while(!feof(y));

            //-------------------------------------------------------------
            cout << "             |          count in yes.txt: " << yi-1;
            if(yi < 10)
            cout << "      |" << endl;
            if(yi >= 10 && yi < 100)
            cout << "     |" << endl;
            if(yi >= 100 && yi < 1000)
            cout << "    |" << endl;
            if(yi >= 1000 && yi < 10000)
            cout << "   |" << endl;
            if(yi >= 10000 && yi < 100000)
            cout << "  |" << endl;
            //-------------------------------------------------------------

            printf("             -------------------------------------\r\n");


            do{ //Read from no.txt

                fgets(records[n],60,f);
                //cout << records[n];
                for(i = 0; i < yi; i++)
                {
                   // cout << "i = " << i << ":" << yes[i] << " n = " << n << ": " << records[n];
                    if(strcmp(records[n],yes[i]) == 0 && strcmp(yes[i],"") != 0)
                    {
                        cout << "MATCH FOUND IN no.txt ON POSITION " << n+1 << ": " << records[n];
                        cc++;
                    }


                }

                n++;
            }
            while((!feof(f)));

            cout << "--------------------" << endl;
            if(cc > 0)
            {
                cout << "TOTAL MATCHES FOUND: " << cc;
            }
            else
            {
                cout << "MATCHES NOT FOUND" << endl;
            }

        }
    }

    fclose(f);
    fclose(y);
    getch();
    return 0;
}
