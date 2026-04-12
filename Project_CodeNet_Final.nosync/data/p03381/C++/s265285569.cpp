#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define dd second
#define ff first
#define N 200005
#define pb push_back
#define pp pair<int,int>
using namespace std;

int n;
int tab[N];

int tab2[N];

main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> tab[i], tab2[i] = tab[i];

    sort(tab2, tab2+n);

    for(int i = 0; i < n; ++i) {
        int val = tab[i];
        int index = lower_bound(tab2, tab2+n, val)- tab2;
        int k = (n-1)/2;
        if(k < index) {
            cout << tab2[k] << " ";
        } else {
            cout << tab2[k+1] << " ";
        }
    }
    cout << endl;

}