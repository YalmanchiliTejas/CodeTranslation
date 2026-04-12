#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
string str;
int main(){
	string left("qwertasdfgzxcvb");
	string right("yuiophjklnm");
	while(cin>>str){
		if(str[0]=='#')
			break;
		int l = str.length();
		int step = 0;
		bool flag;
		if(left.find(str[0],0)!=string::npos){
			flag =true;
		}else{
			flag =false;
		}
		for(int i = 1;i < l;i++){
			int L =left.find(str[i],0);
			if(L!=string::npos){//左で見つかった場合
				if(flag)
					continue;
				else{
					step++;
					flag = true;
				}
			}else{//右で見つかった場合
				if(!flag){//前の手が右手
					continue;
				}else{//前の手が左
					step++;
					flag = false;
				}
			}
		}
		cout <<step<<endl;
	}
	return 0;
}