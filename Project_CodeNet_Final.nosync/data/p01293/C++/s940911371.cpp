#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10005,INF=1<<30;

map<char,int> MA;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<char,int> MA;
    for(char c='1';c<='9';c++) MA[c]=int(c-'0');
    MA['T']=10;
    MA['J']=11;
    MA['Q']=12;
    MA['K']=13;
    MA['A']=14;
    
    while(1){
        char X,Y;cin>>X;
        if(X=='#') break;
        
        vector<vector<string>> S(4,vector<string>(13));
        
        for(int i=0;i<4;i++) for(int j=0;j<13;j++) cin>>S[i][j];
        Y=S[0][0][0];
        
        int ns=0,ew=0;
        
        for(int j=0;j<13;j++){
            vector<pair<int,int>> T(4);
            
            for(int i=0;i<4;i++){
                T[i].first+=MA[S[i][j][0]];
                if(S[i][j][1]==X) T[i].first+=30;
                else if(S[i][j][1]==Y) T[i].first+=15;
                T[i].second=i;
                //cout<<T[i].first<<" ";
            }
            //cout<<endl;
            
            sort(all(T));
            
            if(T[3].second%2==0) ns++;
            else ew++;
            
            if(j!=12) Y=S[T[3].second][j+1][1];
            
            //cout<<T[3].second<<endl;
        }
        
        if(ns>=7) cout<<"NS "<<ns-6<<endl;
        else cout<<"EW "<<ew-6<<endl;
    }
}


