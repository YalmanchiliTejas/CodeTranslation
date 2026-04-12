#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    string ans;
    
    for(int i = 0;i < n;i++){
        cin >> S.at(i);
        sort(S.at(i).begin(),S.at(i).end());
    }
    
    map<char,int> al,bl;

    vector<char> alpha;

    alpha ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


    for(int i = 0;i < 26;i++){
        al[alpha[i]] = 0;
        bl[alpha[i]] = 0;
    }

    int i = 0;

    int Ssize;

    while(i < n){
        if(i == 0){
            Ssize = S.at(i).size();
            for(int j = 0;j < Ssize;j++){
                al[S.at(i).at(j)]++;
            }
        }
        else{
            Ssize = S.at(i).size();
            for(int j = 0;j < Ssize;j++){
                bl[S.at(i).at(j)]++;
            }
            for(int j = 0;j < 26;j++){
                if(al[alpha[j]] >= bl[alpha[j]])
                    al[alpha[j]] = bl[alpha[j]];
                
                bl[alpha[j]] = 0;
            }
        }
        i++;

    }

    for(int j = 0;j < 26;j++){
        if(al[alpha[j]] > 0){
            for(int k = 0;k < al[alpha[j]];k++){
                cout << alpha[j];
            }
        }
    }

    cout << endl;

}