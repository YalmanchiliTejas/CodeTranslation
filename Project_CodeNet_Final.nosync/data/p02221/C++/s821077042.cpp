#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;
int ans[MAX];
int N;
string win;

void DFS(vector<int> &S,int bit,int turn){
    if(turn==N){
        ans[bit]=S[0];
        return;
    }
    
    vector<int> T;
    for(int i=0;i<S.size();i+=2){
        int a=S[i],b=S[i+1];
        if(a>b) swap(a,b);
        if(win[b-a-1]=='1'){
            T.push_back(b);
        }else{
            T.push_back(a);
        }
    }
    
    DFS(T,bit,turn+1);
    
    T.clear();
    
    for(int i=1;i<S.size();i+=2){
        int a=S[i],b=S[(i+1)%int(S.size())];
        if(a>b) swap(a,b);
        if(win[b-a-1]=='1'){
            T.push_back(b);
        }else{
            T.push_back(a);
        }
    }
    
    DFS(T,(bit|(1<<turn)),turn+1);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    cin>>win;
    
    vector<int> S((1<<N));
    for(int i=0;i<(1<<N);i++){
        cin>>S[i];
        S[i]--;
    }
    
    DFS(S,0,0);
    
    for(int i=0;i<(1<<N);i++){
        cout<<ans[i]+1<<endl;
    }
}
