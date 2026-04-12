#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    scanf("%d",&num);
    int s[5005] = {};
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &s[i]);
    }
    sort(s,s+num);
    int ans = 0;
    for(int i = 0; i < num; i++)
    {
        for(int j = i + 1; j < num; j++)
        {
            int dif = s[j] - s[i];
            int k = 2;
            while(*(lower_bound(s, s+num, s[i] + dif *k)) == s[i] + dif * k)
            {
                k++;
            }
            ans = max(ans, k);
        }
    }
    printf("%d\n",ans);
}

