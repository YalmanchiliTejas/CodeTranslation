#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int n;
    deque<int>D;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(n%2)
            D.push_back(x);
        else
            D.push_front(x);
    }
       for(int i=0;i<D.size();i++){
            if(i!=0)
                cout << " ";
            cout << D[i];
        }
        cout << endl;
}
