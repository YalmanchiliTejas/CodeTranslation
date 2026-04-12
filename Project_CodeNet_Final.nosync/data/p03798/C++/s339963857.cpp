#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int N;
string s;

int main(void){
    
    scanf("%d", &N);
    cin >> s;
    
    vector<bool> v(N);
    for(int p = 0; p < 4; ++p){
        
        if(p == 0) v[0] = true, v[1] = true;
        else if(p == 1) v[0] = true, v[1] = false;
        else if(p == 2) v[0] = false, v[1] = true;
        else v[0] = false, v[1] = false;
        
        for(int i = 1; i < N - 1; ++i){
            if(v[i]){
                if(s[i] == 'o') v[i + 1] = (v[i - 1]) ? true : false;
                else v[i + 1] = (v[i - 1]) ? false : true;
            }
            else{
                if(s[i] == 'o') v[i + 1] = (v[i - 1]) ? false : true;
                else v[i + 1] = (v[i - 1]) ? true : false;
            }
        }
        
        bool ans = false;
        if((v[0] && s[0] == 'o' && v[N - 1] && v[1]) || (v[0] && s[0] == 'o' && !v[N - 1] && !v[1])){
            if(v[N - 1] && s[N - 1] == 'o' && v[N - 2] && v[0]) ans = true;
            else if(v[N - 1] && s[N - 1] == 'x' && !v[N - 2] && v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'x' && v[N - 2] && v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'o' && !v[N - 2] && v[0]) ans = true;
        }
        else if((v[0] && s[0] == 'x' && !v[N - 1] && v[1]) || (v[0] && s[0] == 'x' && v[N - 1] && !v[1])){
            if(v[N - 1] && s[N - 1] == 'o' && v[N - 2] && v[0]) ans = true;
            else if(v[N - 1] && s[N - 1] == 'x' && !v[N - 2] && v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'x' && v[N - 2] && v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'o' && !v[N - 2] && v[0]) ans = true;
        }
        else if((!v[0] && s[0] == 'x' && v[N - 1] && v[1]) || (!v[0] && s[0] == 'x' && !v[N - 1] && !v[1])){
            if(v[N - 1] && s[N - 1] == 'o' && !v[N - 2] && !v[0]) ans = true;
            else if(v[N - 1] && s[N - 1] == 'x' && v[N - 2] && !v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'x' && !v[N - 2] && !v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'o' && v[N - 2] && !v[0]) ans = true;
        }
        else if((!v[0] && s[0] == 'o' && !v[N - 1] && v[1]) || (!v[0] && s[0] == 'o' && v[N - 1] && !v[1])){
            if(v[N - 1] && s[N - 1] == 'o' && !v[N - 2] && !v[0]) ans = true;
            else if(v[N - 1] && s[N - 1] == 'x' && v[N - 2] && !v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'x' && !v[N - 2] && !v[0]) ans = true;
            else if(!v[N - 1] && s[N - 1] == 'o' && v[N - 2] && !v[0]) ans = true;
        }
        
        if(ans){
            for(int i = 0; i < N; ++i) printf("%c", (v[i]) ? 'S' : 'W');
            printf("\n");
            return 0;
        }
        
    }
    printf("-1\n");
    
    return 0;
}