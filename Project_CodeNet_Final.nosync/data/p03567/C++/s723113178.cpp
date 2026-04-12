#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include<cmath>
#include<string>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)
#define show(x) cout<< #x << " = " << (x) << endl
#define show_array(arr) REP(i,int((arr).size()))cout<< #arr << "["<<i<<"]"<<"="<<arr[i]<<endl

int main(){

	ios::sync_with_stdio(false);

	string str;
	cin>>str;
	bool isA = false;
	for(int i = 0; i < str.size() -1 ; i++){
		if(str[i] == 'A' && str[i+1] == 'C'){
			isA = true;
		}
	}

	if(isA){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

	return 0;
}
