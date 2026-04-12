#include <iostream>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

string s;
bool bio[2];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> s;
for(int i = 0 ; i < 3 ; ++i){
	bio[s[i] - 'A'] = 1;
}
int br = 0;
for(int i = 0 ; i < 2 ; ++i){
	br += bio[i];
}
if(br == 2){
	cout << "Yes" << endl;
}
else{
	cout << "No" << endl;
}

return 0;
}
