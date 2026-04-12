#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // 整数の入力
    int n;
    int largenum=10000000;
    vector<int> charcounts(26,largenum);
    cin >> n;
    string str;
    for(int i=0;i<n;i++){
        vector<int> tmpcharcounts(26,0);
        cin >> str;
        for(int j=0;j<str.size();j++)
            tmpcharcounts[str[j]-'a']++;
        for(int c=0;c<26;c++)
            if(tmpcharcounts[c]<charcounts[c])
                charcounts[c] = tmpcharcounts[c];
    }
    for(int c=0;c<26;c++)
        if(charcounts[c]<largenum)
            for(int i=0;i<charcounts[c];i++)
                cout << char('a' + c);
    cout << endl;
    return 0;
}
