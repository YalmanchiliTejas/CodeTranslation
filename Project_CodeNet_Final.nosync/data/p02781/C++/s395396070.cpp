#include <iostream>
#include <string>
using namespace std;

int res, K;
string N;

void func(auto& s, int i, int k)
{
    if (k==K) {
        if (s<=N) {
            ++res;
            //cout<<stoi(s)<<endl;
        }
        return;
    }
    if (i>=N.size()) return;
    s[i]='0';
    func(s, i+1, k);
    for(int j='1'; j<='9'; ++j) {
        s[i]=j;
        func(s, i+1, k+1);
        s[i]='0';
    }
}

int main()
{
    cin>>N>>K;
    string a(N.size(), '0');
    res=0;
    func(a, 0, 0);
    cout<<res<<endl;
}
