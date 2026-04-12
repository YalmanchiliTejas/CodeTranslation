#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include<cmath>

#define rep(i, a, b) for (int i=a; i <b; i++)
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef vector< int > vi;

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> ary(n);
    for(int i = 0; i<n;i++) {
        cin >> ary[i];
    }
    sort(ary.begin(), ary.end());
    //for(int i = 0; i<n; i++) {printf("%d ,", ary[i]);}
    //printf("\n");

    int ia, ib, c, ja, jb;
    vector<int> aryb(n);
    
    c = 0; ia = n/2; ib = n/2 - 1; ja = 0; jb = n-1;
    while(ia != n || ib != -1) {
        if(c %2 == 0) {
            if(ia != n) {
                aryb[ia] = ary[ja];
                ja++; ia++;
            }

            if(ib != -1) {
                aryb[ib] = ary[jb];
                jb--; ib--;
            }          
        } else {
            if(ia != n) {
                aryb[ia] = ary[jb];
                ia++; jb--;
            }
            if (ib != -1) {
                aryb[ib] = ary[ja];
                ja++; ib--;
            }
        }
        c++;
    }
    unsigned long long int suma = 0;
    for(int i=0; i < n-1; i++) {
        suma += abs(aryb[i] - aryb[i+1]);
    }
    c = 0; ia = n/2; ib = n/2 - 1; ja = 0; jb = n-1;
    while(ia != n || ib != -1) {
        if(c %2 == 0) {
            if(ia != n) {
                aryb[ia] = ary[jb];
                jb--; ia++;
            }

            if(ib != -1) {
                aryb[ib] = ary[ja];
                ja++; ib--;
            }          
        } else {
            if(ia != n) {
                aryb[ia] = ary[ja];
                ia++; ja++;
            }
            if (ib != -1) {
                aryb[ib] = ary[jb];
                jb--; ib--;
            }
        }
        c++;
    }
    unsigned long long int sumb = 0;
    for(int i=0; i < n-1; i++) {
        sumb += abs(aryb[i] - aryb[i+1]);
    }

    unsigned long long int sum=0;
    if (suma > sumb) {
        sum = suma;
    } else {
        sum = sumb;
    }

    cout << sum << endl;
    return 0;
}