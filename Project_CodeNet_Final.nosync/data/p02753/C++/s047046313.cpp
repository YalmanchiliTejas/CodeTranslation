//Moh_K_Imar .......
//22/08/2020  ... 12,00 .
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string a;
    cin>>a;
    ll counter=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='A'){
            counter++;
        }
    }
    if(counter==0||counter==3)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}

