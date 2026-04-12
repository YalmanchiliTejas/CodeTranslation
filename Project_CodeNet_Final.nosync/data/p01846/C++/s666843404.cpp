#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        string S;cin>>S;
        if(S[0]=='#') break;
        int cnt=1;
        for(int i=0;i<S.size();i++){
            if(S[i]=='/') cnt++;
        }
        
        vector<vector<int>> state(cnt,vector<int>());
        int h=0;
        
        for(int i=0;i<S.size();i++){
            if(S[i]=='/') h++;
            else if(S[i]=='b') state[h].push_back(1);
            else{
                for(int j=0;j<S[i]-'0';j++){
                    state[h].push_back(0);
                }
            }
        }
        
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        state[a][b]--;
        state[c][d]++;
        
        string T;
        
        for(int i=0;i<cnt;i++){
            int ze=0;
            for(int j=0;j<state[i].size();j++){
                if(state[i][j]==1){
                    if(ze) T+=char('0'+ze);
                    T+='b';
                    ze=0;
                }else ze++;
            }
            if(ze) T+=char('0'+ze);
            if(i!=cnt-1) T+='/';
        }
        
        cout<<T<<endl;
    }
}


