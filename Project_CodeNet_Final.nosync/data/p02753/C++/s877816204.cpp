#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

void test_case(){
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int a[2] = {};
    int cnt = 0;
    for( int i = 0 ; i< 3; i++)
        a[s[i]-'A'] = 1;
    rng( i, 0, 2)
        cnt += a[i];
    
    if( cnt > 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
	return 0;
}




