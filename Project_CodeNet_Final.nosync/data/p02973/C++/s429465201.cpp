//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//Abdulhamid Han
//Bismillahirrahmanirrahim
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█
 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lo;
typedef pair< int,int > PII;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)
 
const lo MAX = -1000000000000000000;
const lo MIN = 1000000000000000000;
const lo inf = 1000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 500005;
const lo mod = 1000000007;
 
int n,m,b[li],a[li],k,flag,t;
int cev;
string s;
multiset<int> st;
vector<int> v;
 
int main(void){
	scanf("%d",&n);
	FOR{
		scanf("%d",&a[i]);
	}
	//~ st.insert(inf)
	st.insert(a[1]);
	for(int i=2;i<=n;i++){
		//~ cout<<st.size()<<endl;
		auto it=st.begin();
		//~ it++;
		//~ cout<<*it<<endl;
		if(*it>=a[i]){st.insert(a[i]);continue;}
		it=st.lower_bound(a[i]);
		//~ auto it1=st.upper_bound(a[i]);
		//~ if(st.size()==1){
			//~ it--;
			//~ if(it==st.end()){
				//~ it--;
				//~ st.erase(it);
				//~ st.insert(*it);
				//~ continue;
			//~ }
			//~ else{
				//~ st.insert(a[i]);continue;
			//~ }
		//~ }
		it--;
		//~ if(it==){st.insert(a[i]);continue;}
		//~ if(*it>=a[i]){st.insert(a[i]);continue;}
		
		st.erase(it);
		st.insert(a[i]);
	}
	printf("%d\n",st.size());
	return 0;
}
