#include<bits/stdc++.h>
using namespace std;
int arr[30], brr[30];
int main()
{

    for(int i = 0; i < 26; i++) brr[i] = 55;
    int n;
    scanf("%d",&n);



    for(int i = 0; i < n; i++)
    {
        char s[55];
        memset(arr, 0, sizeof(arr));
        scanf("%s",s);
        for(int j = 0; s[j]; j++)
        {
            arr[s[j] -'a']++;
        }
        for(int i = 0; i < 26; i++)
            brr[i] = min(arr[i], brr[i]);
    }
    for(int i = 0; i < 26; i++)
    {
        while(brr[i]--) printf("%c",i+'a');
    }
    printf("\n");
}
