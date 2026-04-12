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
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FILL(Itr,n) fill((Itr).begin(),(Itr).end(),n)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;
#define MOD 1000000007

set<int> G[10];

bool judge(vector<int> a){
    a.insert(a.begin(),1);
    REP(i,a.size()-1){
        int from = a[i];
        int to = a[i+1];
        if(G[from].find(to)==G[from].end())return false;
    }
    return true;
}

int main(){
    
    int N,M; cin>>N>>M;
    REP(i,M){
        int a,b; cin>>a>>b;
        G[a].insert(b);
        G[b].insert(a);
    }
    
    vector<int> root;
    REP(i,N-1)root.push_back(2+i);
    
    int ans=0;
    do{
        if(judge(root))ans++;
    }while(next_permutation(root.begin(),root.end()));
    
    cout<<ans<<endl;
    
    return 0;
}