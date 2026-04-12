#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N;
    cin >> N;
    char *s;
    s = new char [N];
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    int K;
    cin >> K;
    for(int i=0;i<N;i++){
        if(s[i]!=s[K-1]){
            s[i] = '*';
        }
    }
    for(int i=0;i<N;i++){
        cout << s[i];
    }
    return 0;
}