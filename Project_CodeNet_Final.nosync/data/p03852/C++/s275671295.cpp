#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	//freopen("input16.txt","r",stdin);freopen("output16.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	char a;
	cin>>a;
	if (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
		cout<<"vowel";
	}
	else {
		cout<<"consonant";
	}
	return 0;
}