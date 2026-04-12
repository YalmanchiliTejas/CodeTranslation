#include <bits/stdc++.h>

using namespace std;
long long L[200005],arr[200005],n;

int lis()
{
    multiset<int> last;
    for (int i = 0; i < n; i++) {

        multiset<int>::iterator it = last.lower_bound(arr[i]);

        if (it == last.begin())
            last.insert(arr[i]);

        else {
            it--;

            last.erase(it);
            last.insert(arr[i]);
        }
    }
    return last.size();
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        L[i]=1;
    }
    cout << lis()<<endl;

    return 0;
}
