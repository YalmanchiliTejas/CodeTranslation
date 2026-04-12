/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1147&lang=jp*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;

    while (cin>>n && n>0){
        vector<int> s;

        for (int i=0;i<n;i++){
            int tmp;

            cin>>tmp;
            s.push_back(tmp);
        }
        sort(s.begin(),s.end());
        cout<<accumulate(++s.begin(),--s.end(),0)/(n-2)<<endl;
    }
    return 0;
}