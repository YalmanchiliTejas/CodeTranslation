 #include<bits/stdc++.h>

using namespace std;

int main(){
string s;
cin >> s;
int fa=0,fb=0;
for (int i = 0; i < 3; ++i)
{
    if (s[i] == 'A')
    {
      fa = 1;
    }
    else fb = 1;
}
if (fa ==1 && fb == 1)
{
    cout << "Yes";
}
else cout << "No";
    return 0;
}