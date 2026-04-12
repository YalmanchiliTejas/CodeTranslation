#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
using namespace std;
typedef long long ll;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FOREACH(i,Itr) for(auto (i)=(Itr).begin();(i)!=(Itr).end();(i)++)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))


int cnt[100010];
bool used[100010];

int main(){
    
    int N,Q; cin>>N>>Q;
    for(int i=1;i<=100000;i++)cnt[i]=i;
    REP(i,100010)used[i]=false;
   
    int pos=1;
    used[2]=true;
    REP(i,Q){
        int A,B; cin>>A>>B;
        if(A==pos){
            pos=B;
        }else if(B==pos){
            pos=A;
        }
        swap(cnt[A],cnt[B]);
        used[cnt[pos-1]]=used[cnt[pos]]=used[cnt[pos+1]]=true;
    }
    
    int ans=0;
    for(int i=1;i<=N;i++)if(used[i])ans++;
    cout<<ans<<endl;
    
    return 0;
}
