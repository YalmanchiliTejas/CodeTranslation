#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<n;i++)
#define unsigned long ul
using namespace std;

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
   	int n;
       cin >> n;
    int max = 0;
    int count = 0;
    REP(i, n){
        int s;
        cin >> s;
        if(s>=max){
            max = s;
            count++;
        }
    }
    cout << count << endl;
	return 0;
}
