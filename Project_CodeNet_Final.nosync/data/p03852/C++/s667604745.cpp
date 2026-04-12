//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
string s="aeiou";
char c;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>c;
	size_t f=s.find(c);
	if(f!=string::npos)
	cout<<"vowel";
	else
	cout<<"consonant";
	return 0;
}
