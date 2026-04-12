#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=6005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<char,int> MA;
    MA['y']=1;
    MA['u']=1;
    MA['i']=1;
    MA['o']=1;
    MA['p']=1;
    MA['j']=1;
    MA['k']=1;
    MA['l']=1;
    MA['h']=1;
    MA['n']=1;
    MA['m']=1;
    
    while(1){
        string S;cin>>S;
        if(S[0]=='#') break;
        int cnt=0;
        
        for(int i=1;i<S.size();i++){
            if(MA[S[i-1]]+MA[S[i]]==1) cnt++;
        }
        
        cout<<cnt<<endl;
    }
}

