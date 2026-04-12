#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;
    cin >> x>>y>>z;
    int cm=z,count=0;
    for(int i=0;i<100000;i++){

        cm+=y+z;
        if(cm<=x){
            count++;

        }
        else{
            break;
        }
    }

    
    cout << count<< endl;
}