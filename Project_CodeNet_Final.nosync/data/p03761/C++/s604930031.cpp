#include<iostream>
#include<string>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    string s;
    int abclen[26];
    rep(i,26) abclen[i]=100;
    for(int i=0; i<n; i++){
        cin >> s;
        int len = s.length();
        int tmplen[26];
        rep(j,26) tmplen[j] = 0;
        for(int j=0;j<len; j++){
            int tmp=s[j]-'a';
            tmplen[tmp]++;
        }
        for(int j=0; j<26; j++){
            if(tmplen[j]<abclen[j]){
                abclen[j]=tmplen[j];
            }
        }
    }
    for(int i=0; i<26; i++){
        int tmp=abclen[i];
        if(tmp>0){
            int abc = 'a'+i;
            char sub = abc;
            for(int j=0; j<tmp; j++){
                cout << sub;
            }
        }
    }
    cout << endl; 
    return 0;
}