#include<bits/stdc++.h>
using namespace std;

int L;
string S,T,ans;

int main()
{
    scanf("%d",&L);
    cin >> S >> T;
    ans = "";
    if(S + T > T + S)swap(S,T);

    for(int i = L; i >= 0; i--)
    {
        if(S.size() * i > L)continue;
        if((L - (S.size() * i)) % T.size() == 0)
        {
            for(int j = 0; j < i; j++)ans += S;
            while(L != ans.size())ans += T;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
