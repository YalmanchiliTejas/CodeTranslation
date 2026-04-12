#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int n;
int a[maxn];
int init(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
}
int solve(){
    multiset <int> s;
    #define itr multiset <int> :: iterator
    int c=0;
    for(int i=0;i<n;++i){
        int x=a[i];
        itr p=s.lower_bound(x);
        if(p==s.begin()){
            c++;
            s.insert(x);
        }else{
            --p;
            s.insert(p,x);
            s.erase(p);
        }
    }
    return c;
}
int main(){
	init();
	cout<<solve()<<endl;
    return 0;
}