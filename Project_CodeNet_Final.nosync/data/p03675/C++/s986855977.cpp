#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43

int n;
int a[200007];

const bool is_testing = 0;
int main() { 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    } else {
        //freopen("cpr.in", "r", stdin);
        //freopen("cpr.out", "w", stdout);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    deque<int> d;

    if (n % 2 == 0){
    	for (int i = 0; i < n; i += 2){
    		d.push_back(a[i]);
    		d.push_front(a[i + 1]);
    	}
    } else {
    	for (int i = 0; i < n - 1; i += 2){
    		d.push_front(a[i]);
    		d.push_back(a[i + 1]);
    	}
    	d.push_front(a[n - 1]);
    }

    for (int x : d) printf("%d ", x);
}