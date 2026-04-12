#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    std::deque<int> deq(26,0);
    for (int i=0;i<n;i++) {
        cin>>s;
        std::map<char, int> num;
        for (int j=0;j<s.size();j++) {
            if (i==0) {
                deq[s[j]-97]++;
            } else {
                if (num[s[j]]==0) {
                    num.emplace(s[j],0);
                    num[s[j]]++;
                } else {
                    num.at(s[j])++;
                }
            }
        }
        if (i!=0) {
            for (int j=0;j<26;j++) {
                char cc=j+97;
                if (deq[j]>0) {
                    if (num[cc]==0) {
                        deq[j]=0;
                    } else {
                        if (deq[j]>num[cc]) {
                            deq[j]=num[cc];
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<26;i++) {
        for (int j=0;j<deq[i];j++) {
            char c=i+97;
            cout<<c;
        }
    }
    cout<<endl;
}