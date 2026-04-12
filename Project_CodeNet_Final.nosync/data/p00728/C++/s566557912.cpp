#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int scores[1000];
    int n;
    int min, max;
    int sum = 0;
    int minf = 0, maxf = 0;

    while(cin >> n) {
        if(n == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &scores[i]);
            if(i == 0) {
                min = max = scores[i];
            }
            if(scores[i] < min) {
                min = scores[i];
            } else if(scores[i] > max) {
                max = scores[i];
            }
        }

        minf = 0;
        maxf = 0;
        sum = 0;
        for(int i = 0; i < n; i++) {
            if(!minf && scores[i] == min) {
                minf = 1;
            } else if(!maxf && scores[i] == max) {
                maxf = 1;
            } else {
                sum += scores[i];
            }
        }
        cout << sum / (n - 2) << endl;
    }
}