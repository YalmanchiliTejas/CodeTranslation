#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        multiset<int> LIS;
        int temp;
        cin>>temp;
        LIS.insert(temp);
        for(int i=1;i<n;i++){
            cin>>temp;
            if(temp<=*LIS.begin()){
                LIS.insert(temp);
            }
            else{
                auto p = LIS.lower_bound(temp);
                if(p!=LIS.begin()) p--;
                LIS.erase(p);
                LIS.insert(temp);
            }
        }
        cout<<LIS.size()<<endl;
    }
    return 0;
}
