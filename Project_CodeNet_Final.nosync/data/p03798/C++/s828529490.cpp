#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

char ex(char c){
	return c == 'S' ? 'W' : 'S';
}

string solve(string s, string res){
	int n = s.size();
	rep2(i,1,n-1){
		char c = res[i - 1];
		if (res[i] == 'S')
		{
			if (s[i] == 'o'){
				res.push_back(c);
			} else {
				res.push_back(ex(c));
			}
		}
		else
		{
			if (s[i] == 'o'){
				res.push_back(ex(c));
			} else {
				res.push_back(c);
			}
		}
		
	}
	return res;
}

int check(string s, string res){
	int n = s.size();
	rep(i,n){
		if (i == 0){
			if (s[i] == 'o'){
				if (res[i] == 'S'){
					if (res[i+1] != res.back()){
						return 0;
					} 
				} else {
					if (res[i+1] == res.back()){
						return 0;
					}
				}
			} else {
				if (res[i] == 'S'){
					if (res[i+1] == res.back()){
						return 0;
					} 
				} else {
					if (res[i+1] != res.back()){
						return 0;
					}
				}
			}
		} else if (i == n - 1){
			if (s[i] == 'o'){
				if (res[i] == 'S'){
					if (res[i-1] != res[0]){
						return 0;
					} 
				} else {
					if (res[i-1] == res[0]){
						return 0;
					}
				}
			} else {
				if (res[i] == 'S'){
					if (res[i-1] == res[0]){
						return 0;
					} 
				} else {
					if (res[i-1] != res[0]){
						return 0;
					}
				}
			}
		} else {
			if (s[i] == 'o'){
				if (res[i] == 'S'){
					if (res[i+1] != res[i-1]){
						return 0;
					} 
				} else {
					if (res[i+1] == res[i-1]){
						return 0;
					}
				}
			} else {
				if (res[i] == 'S'){
					if (res[i+1] == res[i-1]){
						return 0;
					} 
				} else {
					if (res[i+1] != res[i-1]){
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	string res = "SS";

	res = solve(s, res);
	if (check(s,res)){
		cout << res << endl;
		return 0;
	}
	res = "SW";
	res = solve(s, res);
	if (check(s, res))
	{
		cout << res << endl;
		return 0;
	}
	res = "WS";
	res = solve(s, res);
	if (check(s,res)){
		cout << res << endl;
		return 0;
	}
	res = "WW";
	res = solve(s, res);
	if (check(s,res)){
		cout << res << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}


