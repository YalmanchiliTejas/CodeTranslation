#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>
using namespace std;
typedef unsigned long long LL;
typedef pair<LL,LL> P;


LL ret[500][500];
int main(){
	LL N;
    scanf("%llu",&N);
    std::vector<LL> S(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%llu",&S[i]);
    }
    std::vector<LL> T(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%llu",&T[i]);
    }
    std::vector<LL> U(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%llu",&U[i]);
    }
    std::vector<LL> V(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%llu",&V[i]);
    }

	for(int R=0;R<64;R++){
		set<int> a0r,a0c,s0r,s0c;
		set<int> a1r,a1c,s1r,s1c;
		LL f=(1LLU<<R);
		for(int i=0;i<N;i++){
			if(S[i]==0){
				if(U[i]&f){
					a1r.insert(i);
				}
				else{
					s0r.insert(i);
				}
			}
			else{
				if(U[i]&f){
					s1r.insert(i);
				}
				else{
					a0r.insert(i);
				}
			}
		}
		for(int i=0;i<N;i++){
			if(T[i]==0){
				if(V[i]&f){
					a1c.insert(i);
				}
				else{
					s0c.insert(i);
				}
			}
			else{
				if(V[i]&f){
					s1c.insert(i);
				}
				else{
					a0c.insert(i);
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j:a1c){
				//cerr << "a " << i << ", " << j << endl;
				ret[i][j]|=f;
			}
		}
		for(int i:a1r){
			for(int j=0;j<N;j++){
				//cerr << "b " << i << ", " << j << endl;
				ret[i][j]|=f;
			}
		}
		if((s1r.size()+s0r.size()==1)||(s1c.size()+s0c.size()==1)){
			if((s1r.size()==1&&s1c.size())||(s1r.size()&&s1c.size()==1)){
				if(s1c.size()){
					for(auto i:s1r){
						for(auto j:s1c){
							//cerr << "c " << i << ", " << j << endl;
							ret[i][j]|=f;
						}
					}
				}
			}
			else if(s1r.size()==1){
				if(a1c.size()==0){
					for(auto i:s1r){
						for(auto j:s0c){
							//cerr << "d " << i << ", " << j << endl;
							ret[i][j]|=f;
						}
					}
				}
			}
			else if(s1c.size()==1){
				if(a1r.size()==0){
					for(auto i:s0r){
						for(auto j:s1c){
							//cerr << "e " << i << ", " << j << endl;
							ret[i][j]|=f;
						}
					}
				}
			}
		}
		else{
			vector<int> r,c;
			for(auto i:s0r){
				r.push_back(i);
			}
			for(auto i:s1r){
				r.push_back(i);
			}
			for(auto i:s0c){
				c.push_back(i);
			}
			for(auto i:s1c){
				c.push_back(i);
			}
			for(int i=0;i<r.size();i++){
				for(int j=0;j<c.size();j++){
					if((i+j)%2==0){
						ret[r[i]][c[j]]|=f;
					}
				}
			}
		}
	}
#if 1
	for(int i=0;i<N;i++){
		LL a=ret[i][0];
		for(int j=1;j<N;j++){
			if(S[i]==0){
				a&=ret[i][j];
			}
			else{
				a|=ret[i][j];
			}
		}
		if(a!=U[i]){
			//cerr << "aaa " << a << ", " << i << ", " << U[i] << endl;
			cout << -1 << endl;
			return 0;
		}
	}
	for(int j=0;j<N;j++){
		LL a=ret[0][j];
		for(int i=1;i<N;i++){
			if(T[j]==0){
				a&=ret[i][j];
			}
			else{
				a|=ret[i][j];
			}
		}
		if(a!=V[j]){
			//cerr << "bbb " << a << ", " << j << ", " << V[j] << endl;
			cout << -1 << endl;
			return 0;
		}
	}
#endif

	for(int i=0;i<N;i++){
		auto sp="";
		for(int j=0;j<N;j++){
			cout << sp << ret[i][j];
			sp=" ";
		}
		cout << endl;
	}

    return 0;
}
