#include <bits/stdc++.h>
using namespace std;

#define INF (1<<29)

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    for(int i=0; i<n; i++) cin >> S[i];
    
    int ch[55][155];
    for(int i=0; i<55; i++){
        for(int j=0; j<155; j++){
            ch[i][j] = 0;
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<S[i].size(); j++){
            ch[i][S[i][j]]++;
        }
    }
    vector<int> c(155,INF);
    for(int cha='a'; cha<='z'; cha++){
        for(int i=0; i<n; i++){
            c[cha] = min(c[cha], ch[i][cha]);
        }
    }
    
    vector<char> s;
    for(char cha='a'; cha<='z'; cha++){
        if(c[cha]>0){
            while(c[cha]!=0){
                s.push_back(cha);
                c[cha]--;
            }
        }
    }
    sort(s.begin(),s.end());
    for(int i=0; i<s.size(); i++){
        cout << s[i];
    }
    cout << endl;
}
