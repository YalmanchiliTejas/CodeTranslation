#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
#include<stdio.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;



int main(void){
	set<char>left;
	left.insert('a');
	left.insert('b');
	left.insert('c');
	left.insert('d');
	left.insert('e');
	left.insert('f');
	left.insert('g');
	left.insert('q');
	left.insert('r');
	left.insert('s');
	left.insert('t');
	left.insert('v');
	left.insert('w');
	left.insert('x');
	left.insert('z');
	string s;
	while(true){
		cin>>s;
		int hand=0,ans=0;
		if(s=="#")break;
		for(int i=0;i<s.length();i++){
			if(i==0){
				if(left.count(s[i])==1){
					hand=0;
				}
				else hand=1;
			}
			else{
				if(hand==0){
					if(left.count(s[i])==1)hand=0;
					else{
						ans++;
						hand=1;
					}
				}
				else{
					if(left.count(s[i])==1){
						ans++;
						hand=0;
					}
					else hand=1;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
