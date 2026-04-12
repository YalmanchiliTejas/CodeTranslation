#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define FI freopen("input.txt","r",stdin)
#define FO freopen("output.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
int main()
{
    char ch,arr[3];
    bool f = false;
    for(int i=0;i<3;i++){
        scanf("%c",&ch);
        arr[i]=ch;
        if(i>0 && arr[i]!=arr[i-1])
        f = true;

        }
        if(f)
            printf("Yes\n");
            else
                printf("No\n");

    return 0;
}

