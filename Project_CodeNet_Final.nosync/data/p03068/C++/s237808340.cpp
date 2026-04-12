#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

int main(){
	int n,k;
	string s;
	cin>>n>>s>>k;
	char tar=s[k-1];

	for (int i = 0; i < s.size(); ++i){
		if(s[i]==tar)
			cout<<tar;
		else
			cout<<'*';
	}

	cout<<endl;

}
