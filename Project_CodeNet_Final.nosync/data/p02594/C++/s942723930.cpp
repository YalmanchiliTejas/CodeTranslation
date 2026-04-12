#include <bits/stdc++.h>
#define ll long long
#define rep(a, b, c, i) for (int i = a; i < b; i += c)
#define ff first
#define ss second
#define newl "\n"


using namespace std;

class AirConditioner{
public:
	string turn(int x){
		return x >= 30 ? "Yes" : "No";
	}
};

int main(){
	int t;
	cin >> t;
	AirConditioner ac;
	cout << ac.turn(t) << newl;
}
