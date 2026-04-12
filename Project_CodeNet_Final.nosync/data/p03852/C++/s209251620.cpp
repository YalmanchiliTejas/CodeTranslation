#include <bits/stdc++.h> 
#define forn(i,a,b) for(int i=a; i<=b; i++)
#define ford(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char c;
	cin>>c;
	if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o') cout<<"vowel\n";
	else cout<<"consonant\n";
	return 0;
}