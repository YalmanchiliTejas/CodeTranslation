#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fore(i,a,b) for(int i=a,almo5t=b;i<almo5t;++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 0;

typedef long long int ll;

using namespace std;

int main(){
    int n;cin>>n;
    int words[n][28];
    //rellenar matrices
    std::fill(*words,*words + n*28,0);
    string out;
    fore(i,0,n){
        string val;cin>>val;
        int s = SZ(val);
        fore(j,0,s){
            words[i][val[j]-97]++;
        }
    }
    fore(i,0,28){
        int min = 60;
        fore(j,0,n){
            if(words[j][i]<min){
                min = words[j][i];
            }
        }
        if(min == 60)min = 0;
        fore(j,0,min){
            out += (char)(97+i);
        }
    }
    cout<<out;
	return 0;
}