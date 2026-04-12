#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=105,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int K;cin>>K;
    
    if(K==1){
        cout<<(int(S.size())-1)*9+int(S[0]-'0')<<endl;
    }else if(K==2){
        ll ans=0;
        ans+=int(S[0]-'0'-1)*(int(S.size())-1)*9;
        string T;
        T+=S[0];
        while(T.size()<S.size()) T+='0';
        for(int j=1;j<S.size();j++){
            for(char c='1';c<='9';c++){
                T[j]=c;
                if(S>=T) ans++;
                T[j]='0';
            }
        }
        
        ans+=(int(S.size())-1)*(int(S.size())-2)/2*9*9;
        
        cout<<ans<<endl;
    }else{
        ll ans=0;
        ans+=(int(S.size())-1)*(int(S.size())-2)*(int(S.size())-3)/6*9*9*9;
        
        ans+=int(S[0]-'0'-1)*int(S.size()-1)*int(S.size()-2)/2*9*9;
        
        string T;
        T+=S[0];
        while(T.size()<S.size()) T+='0';
        for(int j=1;j<S.size();j++){
            for(int k=j+1;k<S.size();k++){
                for(char c='1';c<='9';c++){
                    for(char d='1';d<='9';d++){
                        T[j]=c;
                        T[k]=d;
                        if(S>=T) ans++;
                        T[j]='0';
                        T[k]='0';
                    }
                }
            }
        }
        
        cout<<ans<<endl;
    }
}
