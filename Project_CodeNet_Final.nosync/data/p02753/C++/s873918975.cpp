#include <bits/stdc++.h>

typedef long long ll;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)

ll mod=1e9+7;

using namespace std;


ll inputValue(){
	ll a;
	cin >> a;
	return a;
};

void inputArray(int * p, ll a){
	rep(i, a){
		cin >> p[i];
	}
};

template<typename T>
void inputVector(vector<T>& p, ll a){
	rep(i, a){
		T input;
		cin >> input;
		p.emplace_back(input);
	}
}


template <typename T>
void output(T a) {
	cout << a << "\n";
}

int main(int argc, const char * argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    string s;
    cin >> s;
    
    if(s[0] !=s[1])
        cout << "Yes" << endl;
    else if(s[1]!=s[2])
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;


	return 0;
}

