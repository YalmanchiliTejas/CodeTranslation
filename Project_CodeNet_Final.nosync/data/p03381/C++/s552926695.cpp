#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200100];
int brr[200100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {scanf("%d",&arr[i]);brr[i]=arr[i];}
    sort(brr,brr+n);
    for (i=0;i<n;i++) {
        if (arr[i]<=brr[n/2-1]) printf("%d\n",brr[n/2]);
        else printf("%d\n",brr[n/2-1]);
    }

    return 0;
}
