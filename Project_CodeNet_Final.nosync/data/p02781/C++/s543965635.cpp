#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	string s;
	cin>>s;
	int d=s.size();
	int c;
	cin>>c;
	ll ans=0;
	if(c==3){
		for(int i=0; i<d; i++){
			for(int j=i+1; j<d; j++){
				for(int k=j+1; k<d; k++){
					if(i>0) ans+=9*9*9;
					else{
						ans+=(s[0]-'0'-1)*9*9;
						
						for(int l=1; l<10; l++){
							for(int m=1; m<10; m++){
								string t; t+=s[0];
								for(int n=1; n<d; n++){
									if(n==j) t+=(char)('0'+l);
									else if(n==k) t+=(char)('0'+m);
									else t+='0';
								}
								if(t<=s) ans++;
							}
						}
					}
				}
			}
		}
	}else if(c==2){
		for(int i=0; i<d; i++){
			for(int j=i+1; j<d; j++){
					if(i>0) ans+=9*9;
					else{
						ans+=(s[0]-'0'-1)*9;
						
						for(int l=1; l<10; l++){
                          string t; t+=s[0];
								for(int n=1; n<d; n++){
									if(n==j) t+=(char)('0'+l);
									else t+='0';
								}
								if(t<=s){
                                  ans++;
                                }
						}
					}
			}
		}
	}else{
		ans=(s[0]-'0');
		ans+=9*(d-1);
	}
	cout<<ans<<endl;
	return 0;
}