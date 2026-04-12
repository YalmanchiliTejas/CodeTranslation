#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define LOOP(i) while(i--)
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

vector<string> split_naive(const string &s, char delim) {
	vector<string> elems;
	string item;
	for(char ch:s){
		if(ch==delim){
			if(!item.empty()) elems.push_back(item);
			item.clear();
		}
		else{
			item += ch;
		}
	}
	if(!item.empty()) elems.push_back(item);
	return elems;
}

int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	vector<pair<int,int>> P;
	while(true){
		int p,s;
		scanf("%d,%d",&p,&s);
		if(!p && !s) break;
		P.emplace_back(p,s);
	}

	sort(ALL(P),PAIRCOMP(second,>));
	vector<int> R(P.size());
	int rank=1;
	R[0] = rank;
	for(int i=1,ei=P.size();i<ei;i++){
		if(P[i].second!=P[i-1].second){
			rank++;
		}
		R[i] = rank;
	}
	map<int,int> Q;
	for(int i=0,ei=P.size();i<ei;i++){
		Q.emplace(P[i].first,R[i]);
	}

	int N;
	while(cin>>N){
		out(Q[N]);
	}
	
	return 0;
}
