#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
        int n;
        cin >> n;
        vector<long> group;
        for(int i=0;i<n;i++){
                long a;
                cin >> a;

                if(group.size() == 0 || group[0] >= a){
                        //cout << "Insert top " << a << endl;
                        group.insert(group.begin(), a);
                }else{
                        auto pos = lower_bound(group.begin(), group.end(), a);
                        --pos;
                        //cout << "Update " << *pos << " to " << a << endl;
                        *pos = a;
                }
        }

        cout << group.size() << endl;
}