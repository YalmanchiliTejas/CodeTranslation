#include <bits/stdc++.h>

#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int x[n],a[n],c,d;
    for(int i=0;i<n;i++){
    	cin>>x[i];
    	a[i]=x[i];
    }
    sort(a,a+n);
    c=a[(n/2)-1];
    d=a[n/2];
    for(int i=0;i<n;i++){
    	if(x[i]>=d){
    		cout <<c<<endl;
    	}
    	else{
    		cout << d<<endl;
    	}
    }


    

    return 0;
}
