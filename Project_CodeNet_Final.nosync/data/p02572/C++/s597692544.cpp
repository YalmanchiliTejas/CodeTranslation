#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

ll n,a;
ll rpta,suma=0;
//string ws="aji";

vector<ll> nros;
int main() {
	// your code goes here
	cin >> n;
    
    while(n){
        cin >> a;
        nros.push_back(a);     
        n--;
    }
    vector<ll> sumas_acum(nros.size()+1);
    for(int i=1; i< (int)sumas_acum.size();i++){
        sumas_acum[i]=sumas_acum[i-1]+nros[i-1];
       // cout << sumas_acum[i]<<" ";
    }

    for(int i=0 ; i<(int)nros.size()-1;i++){
            suma=0;     
        /*for(int j=i+1; j<nros.size(); j++){
            
            suma = (suma%M   + nros[j]%M)%M;
        }*/
        suma = (sumas_acum[nros.size()]-sumas_acum[i+1])%M;
        suma= (suma *nros[i]%M)%M;
        rpta=(rpta%M+suma)%M;
    }
  
    cout <<  rpta<< endl;
  
 
}