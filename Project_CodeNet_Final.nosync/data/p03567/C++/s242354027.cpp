#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007

int main () {
    char s[10];
    scanf("%s",s);
    int n = strlen(s);
    int f = 0;
    for(int i = 0; i < n-1; i++)
        if(s[i] == 'A' && s[i+1] == 'C') f = 1;
    printf("%s\n",f == 1 ? "Yes" : "No" );
    return 0;
}