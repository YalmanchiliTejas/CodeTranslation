#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pi 3.14159265358979323846264
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vl vector <long long>
#define vpii vector <pair <int, int> >
#define ll long long
#define fi first
#define se second
int a, b, c, d;
int main() {
    cin >> a >> b >> c;
    d = a*100+b*10+c;
    if (d%4==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}