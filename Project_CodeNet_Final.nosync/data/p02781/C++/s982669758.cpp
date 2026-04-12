#include <bits/stdc++.h>
using namespace std;

int rec(vector<int> &n, int k)
{
    if(n.size() < k) return 0;
    if(n[0] == 0){
        vector<int> m(n.size()-1);
        copy(n.begin()+1, n.end(), m.begin());
        return rec(m, k);
    }else if(n[0] == -1){
        if(n.size()-1 <k) return 0;
        int c1 = 1, c2 = 1;;
        for (int i = 0; i < k; i++)
        {
            c1 *= n.size()-1-i;
            c1 *= 9;
            c2 *= i+1;
        }
        return c1/c2;
    }

    int ans = 0;
    if(k == 1){
        ans = n[0] + (n.size()-1)*9;
    }else{
        vector<int> m(n);
        m[0] = -1;
        ans += rec(m, k);
        ans += (n[0]-1) * rec(m, k-1);
        m[0] = 0;
        ans += rec(m, k-1);
    }

    return ans;
}

void Main()
{
    string s;
    int k;
    cin >> s >> k;
    vector<int> n(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        n[i] = s[i] - '0';
    }
    int ans = rec(n, k);
    
    cout << ans << endl;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Main();
    return 0;
}
