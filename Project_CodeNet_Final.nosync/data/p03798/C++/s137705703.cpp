#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n;
    string s;
    cin >> n >> s;
    s=s[n-1]+s+s[0];
    vector<bool> ss(n+2),sw(n+2),ws(n+2),ww(n+2);
    ss[0]=true; ss[1]=true;
    sw[0]=true; sw[1]=false;
    ws[0]=false; ws[1]=true;
    ww[0]=false; ww[1]=false;

    vector<bool> animal(n+2);

    for(int i=0;i<4;i++){
        if(i==0) animal=ss;
        if(i==1) animal=sw;
        if(i==2) animal=ws;
        if(i==3) animal=ww;

        for(int i=1;i<=n;i++){
            if(s[i]=='o'){
                //sheep says o
                if(animal[i]){
                    animal[i+1]=animal[i-1];
                }//wolf says o
                else if(!animal[i]){
                    animal[i+1]=!animal[i-1];
                }
            }else{
                //sheep says x
                if(animal[i]){
                    animal[i+1]=!animal[i-1];   
                }//wolf says x
                else if(!animal[i]){
                    animal[i+1]=animal[i-1];
                }
            }
        }
        if(animal[0]==animal[n]&&animal[1]==animal[n+1]){
            for(int i=1;i<=n;i++){
                if(animal[i]) cout << "S";
                else cout << "W";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}