#include <iostream>
#include <cstdio>
#include <string>
 
//#define PI 3.141592653589
 
using namespace std;
 
 
 
int main()
{
    int n;
    string indication[10000];
     
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        for (int i=0; i<n; i++)
        {
            cin >> indication[i];
        }
        /*
        for (int i=0; i<n; i++)
        {
            //cin >> indication[i];
            cout << indication[i];
        }
        */
         
        int dice[6] = {1, 2, 3, 5, 4, 6};
        int temp;
         
        int sum = 1;
        for (int i=0; i<n; i++)
        {
            if (indication[i] == "North")
            {
                temp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[3];
                dice[3] = temp;
            } else if (indication[i] == "East") {
                temp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[2];
                dice[2] = temp;
            } else if (indication[i] == "West") {
                temp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[4];
                dice[4] = temp;
            } else if (indication[i] == "South") {
                temp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[1];
                dice[1] = temp;
            } else if (indication[i] == "Right") {
                temp = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[3];
                dice[3] = dice[4];
                dice[4] = temp;
            } else if (indication[i] == "Left") {
                temp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[3];
                dice[3] = dice[2];
                dice[2] = temp;
            }
            sum += dice[0];
            //cout << "sum = " << sum << endl;
        }
         
        //cout << "sum = " << sum << endl;
        cout << sum << endl;
    }
     
    return 0;
}