#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 2e5 + 7;
struct pack{
	int minN , maxN;
	bool operator <(const pack a)const{return minN < a.minN;}
}now[MAXN];
int N;

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].minN = read(); now[i].maxN = read();
		if(now[i].minN > now[i].maxN) swap(now[i].minN , now[i].maxN);
	}
	sort(now + 1 , now + N + 1);
	int maxInd = 1;
	for(int i = 2 ; i <= N ; ++i)
		if(now[maxInd].maxN < now[i].maxN)
			maxInd = i;
	int minN = now[1].maxN , maxN = now[maxInd].minN;
	for(int i = 2 ; i <= N ; ++i)
		if(i != maxInd){
			minN = min(minN , now[i].maxN);
			maxN = max(maxN , now[i].minN);
		}
	long long ans = 1ll * (maxN - now[1].minN) * (now[maxInd].maxN - minN);
	if(maxInd != 1){
		multiset < int > s;
		s.insert(now[1].maxN);
		for(int i = 2 ; i <= N ; ++i)
			s.insert(now[i].minN);
		ans = min(ans , 1ll * (now[maxInd].maxN - now[1].minN) * (*--s.end() - *s.begin()));
		for(int i = 2 ; i <= N ; ++i)
			if(i != maxInd){
				s.erase(s.find(now[i].minN));
				s.insert(now[i].maxN);
				ans = min(ans , 1ll * (now[maxInd].maxN - now[1].minN) * (*--s.end() - *s.begin()));
			}
	}
	cout << ans;
	return 0;
}
