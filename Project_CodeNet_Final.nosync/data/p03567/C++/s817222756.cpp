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
char s[10];
int main() {
    scanf("%s", s);
    for (int i=0;i<strlen(s);i++) {
        if (s[i]=='A'&&s[i+1]=='C') {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}