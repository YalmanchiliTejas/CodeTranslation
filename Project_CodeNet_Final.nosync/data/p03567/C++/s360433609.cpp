#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define gc getchar
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define x1 uvuvwevwevwe
#define y1 onyetenyevwe
#define x2 ugwemubwem
#define y2 ossas
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
template <typename T> void scan(T &angka){
	angka=0;char input=gc();T kali=1;
	while(!(48<=input&&input<=57)){	if(input=='-')	kali=-1;input=gc();}
	while(48<=input&&input<=57)	angka=(angka<<3)+(angka<<1)+input-48,input=gc();angka*=kali;
}
template <typename T1,typename T2> void scan(T1 &angka1,T2 &angka2){
	scan(angka1);scan(angka2);
}
string input;
int main()
{
	bool ans=false;
	cin>>input;
	for(int i=0;i<input.length()-1;i++)
	{
		if(input[i]=='A'&&input[i+1]=='C')
			ans=true;
	}
	cout<<((ans)?"Yes":"No")<<endl;
}