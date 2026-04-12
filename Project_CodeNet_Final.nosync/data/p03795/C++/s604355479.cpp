#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<(n>=15 ? n*800 - (n/15)*200: n*800 );
}
