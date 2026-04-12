#include<bits/stdc++.h>
using namespace std;

int arr[200200];
int srt[200200];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        srt[i] = arr[i];
    }
    sort(srt, srt+n);
    int l = n/2;
    int an1 = srt[l-1];
    int an2 = srt[l];

    for(int i = 0; i < n; i++){
        if (arr[i] <= an1) printf("%d\n", an2);
        else printf("%d\n", an1);
    }

    return 0;
}