#include <bits/stdc++.h>
using namespace std;

long long int n, i, j, a = 1, d[6] = {1, 2, 3, 4, 5, 6};
char s[5];

main(){
    for(;scanf("%lld", &n),n;a=1){
        for(j = 0; j < 6; ++j){
            d[j] = j + 1;
        }
        j = 4;
        for(i = 0; i < n; ++i, j=4){
            scanf(" %s", s);
            switch(s[0]){
                case 'R':
                    swap(d[1], d[2]);
                    swap(d[4], d[2]);
                    swap(d[4], d[3]);
                    break;
                case 'L':
                    swap(d[1], d[3]);
                    swap(d[4], d[3]);
                    swap(d[4], d[2]);
                    break;
                case 'N':
                    --j;
                case 'W':
                    --j;
                case 'E':
                    --j;
                case 'S':
                    swap(d[0], d[j]);
                    swap(d[5], d[j]);
                    swap(d[5], d[5 - j]);
                    break;
            }
            a += d[0];
        }
        cout << a << endl;
    }
    return 0;
}