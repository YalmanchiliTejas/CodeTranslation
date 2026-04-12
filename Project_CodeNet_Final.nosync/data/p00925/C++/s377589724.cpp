#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

char str[1005];
ll T;

ll parse1() {
    int len = strlen(str);
    ll cN = 1;
    ll totV = 0;
    for (int i = 0; i < len; i+= 2) {
        cN *= (str[i]-'0');
        if (i == len-1 || str[i+1] == '+') {
            totV += cN;
            cN = 1;
        }
    }
    return totV;
}

ll parse2() {
    int len = strlen(str);
    ll cN = (str[0]-'0');
    for (int i = 2; i < len; i += 2) {
        if (str[i-1] == '+') {
            cN += (ll)(str[i]-'0');
        } else {
            cN *= (long long)(str[i]-'0');
        }
    }
    return cN;
}

int main() {
    scanf ("%s ", str);
    scanf ("%lld", &T);
    int c1 = (parse1() == T);
    int c2 = (parse2() == T);
    if (c1 && c2) {
        printf ("U\n");
    } else if (c1) {
        printf ("M\n");
    } else if (c2) {
        printf ("L\n");
    } else {
        printf ("I\n");
    }

    return 0;
}