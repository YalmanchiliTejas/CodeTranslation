//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <random>
#include <time.h>
#include <cassert>


#define prev askdnsajd
#define rank asasdmdnasd
#define next lsjndajbs
#define hash asmdklansd
#define index asdklnas
#define right sld
#define left sldl
using namespace std;

typedef long long ll;
typedef long double dbl;

template<class T>
void print(vector<T> s){
    for (T x : s)
        cout << x << " ";
    cout << endl;
}

mt19937 mrand(random_device{} ());
int rnd() {
	return mrand();
}


int main(){
    srand(17);
 	ios_base::sync_with_stdio(0);
 	int n;
 	cin >> n;
 	vector<int> s(n);
 	int cnt = 0;
 	multiset<int> lst;
 	for (int i = 0; i < n; i++){
 		cin >> s[i];
 		if (lst.size() > 0 && *(lst.begin()) < s[i])
 			lst.erase(--lst.lower_bound(s[i]));
 		else
 			cnt++;
 		lst.insert(s[i]);
 	}
 	cout << cnt << endl;
    return 0;
}