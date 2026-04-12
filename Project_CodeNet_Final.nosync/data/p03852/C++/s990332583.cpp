#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf = 999999999;
const double pi = acos(-1);

#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define mod(i) ((i)%(ll)(1e9 + 7))
#define divm(a,b) (mod(a * modpow((ll)b,(ll)(1e9+5))))
#define rsort(a,b,c) sort(a, b, greater<c>())

ll modpow(ll i,ll j){ ll tmp=1; while(j){ if(j%2)tmp=mod(tmp*i);i=mod(i*i);j/=2;}return tmp;}

///////////////////////////////////////////////////////////////////////////

int main(){
	
	char c;
	cin >> c;
	switch(c){
	    case 'a':
	    case 'i':
	    case 'u':
	    case 'e':
	    case 'o':
	        cout << "vowel" << endl;
	        return 0;
	}
	cout << "consonant" << endl;
	return 0;
}