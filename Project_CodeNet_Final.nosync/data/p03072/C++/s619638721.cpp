#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b = 0,c =0,d =0,x = 0;
    cin >> a;
    vector<int> H(a); 
    for(int i =0; i < a; i++){
        cin >> H.at(i);
        if( i != 0){
            if( H.at(i) > c){
                c = H.at(i);
            }
        }
        if(H.at(i) >= c && H.at(i) >= d ){
            x++;
        }
        if( i == 0){
            c = H.at(i);           
        }
        d = H.at(i);
    }
    cout << x;
   cin >> a;
 }