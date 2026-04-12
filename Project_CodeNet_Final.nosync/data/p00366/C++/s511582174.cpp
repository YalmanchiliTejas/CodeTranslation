#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n,m=0;
		cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        m=max(a[i],m);
    }
    set<int> s;
    for(int i=1;i<=m;i++) if(m%i==0)s.insert(i);
    int d=0;
    for(int i=0;i<n;i++){
        d+=*(s.lower_bound(a[i]))-a[i];
    }
    cout<<d<<endl;
}

