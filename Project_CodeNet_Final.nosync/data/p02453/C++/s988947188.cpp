#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long int n,buf;
    vector<long long int> a;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>buf;
        a.push_back(buf);
    }

    long long int n_q;
    vector<long long int> q;

    cin>>n_q;
    for(int i=0;i<n_q;i++){
        cin>>buf;
        q.push_back(buf);
    }

    for(int i=0;i<n_q;i++){
        decltype(a)::iterator it=lower_bound(a.begin(),a.end(),q[i]);
    
        if(it!=a.end()){
            size_t pos = distance(a.begin(),it);
            cout<<pos<<endl;
        }
        if(it==a.end() && *it!=a[i]){
            cout<<n<<endl;
        }else if(it==a.end() && *it==a[i]){
            size_t pos = distance(a.begin(),it);
            cout<<pos<<endl;
        }
    }

    return 0;
}

