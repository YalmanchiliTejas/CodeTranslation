#include <iostream>
#include <cmath>

using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)

int main(){
    int n,t,e; cin>>n>>t>>e;
    rep(i,n){
        int x; cin>>x;
        if((t+e)%x<=e){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}