#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); //cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define fs first
#define sc second

using namespace std;
typedef long long ll;
typedef long double ld;
char VOW[] = {'a','e','u','o','i','A','E','U','O','I'};

int a, b, c;
string s;

void saitama(){
//	freopen("INPUT.txt","r",stdin);	
	cin >> a;
	cin >> s;
	cin >> b;
	for (int i=0; i<s.size(); ++i){
		if (s[i] != s[b-1]){
			cout << '*';
		} else {
			cout << s[b-1];
		}
	}
}	

int main(){ FIO;
	saitama();
return 0;}