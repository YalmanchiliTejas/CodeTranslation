#include <bits/stdc++.h>
#define ll long long
#define INF INT_MAX 
#define mod 1000000007
using namespace std;
int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    int K;
    cin >> K;

    for(int i=0;i<s.size();i++){
        if(s[i]!=s[K-1]){
            s[i] = '*';
        }
    }
    cout << s << endl;

}