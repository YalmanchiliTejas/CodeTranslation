#include <bits/stdc++.h>
using namespace std;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
//##define FOR(k) "int i=0;i<k;i++"
//特定文字の個数を数える
int search(string s){
	int n=s.size();
	int num = 0;

	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			num++;
		}
	}
	return num;
}

int main(){
    int n,k;
    string s;
    char t;
    cin >> n>>s>>k;
    t = s[k-1];
    for(int i=0;i<s.length();i++){
        if(s[i]!=t){
            s[i]='*';
        }
    }
    cout << s << endl;

}