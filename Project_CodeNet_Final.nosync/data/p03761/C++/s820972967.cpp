#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD = 1000000007;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0;i<N;i++){
        cin >> S[i];
        sort(S[i].begin(),S[i].end());
    }
    vector<map<char,int>> mpl(N);
    for(int i=0;i<N;i++){
        for(auto x : S[i]){
            mpl[i][x]++;
        }
    }
    int ans = 0;
    for(int i=0;i<26;i++){
        char k = char('a'+i);        
        int s = 51;
        for(int j=0;j<N;j++){
            s = min(s,mpl[j][k]);
        }
        for(int i=0;i<s;i++) cout << k;
    }
    cout << endl;

}
