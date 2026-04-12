#include <bits/stdc++.h>

#include <cstdlib>  // abs() for integer 絶対値求めやつ

#include <cmath>    // abs() for float, and fabs()

#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i = 0; i< (n);i++)

#define SORT(a) sort((a).begin(),(a).end());

#define che(a,string) cout<<string<<":"<<(a)<<endl;

#define ch(a,string) cout<<string<<":"<<(a)<<" ";

using namespace std;

typedef pair<int,int> p;

int main(){
	int n;
	cin >>n;
	int wari = n/15 * 200;
	cout<<800*n - wari<<endl;

}
