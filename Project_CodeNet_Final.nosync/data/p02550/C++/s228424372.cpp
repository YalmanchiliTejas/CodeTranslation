#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]){
    ll n;
    int x,m;
    cin >> n >> x >> m;
    set<int> s; //集合

    ll sum=0;
    ll c;
    ll a=x;
    int k=0;
    int zero=1;
    while(true){
        c=s.size();
        s.insert(a);
        if(c==s.size()) break;//aを加えてもサイズが変わってない
        k++;
        sum+=a;
        a%=m;
        a*=a;
        a%=m;
        if(a==0){
            zero=0;
            break;
        }
    }
    int l=0;
    ll b=x;
    ll sum2=0;
    while(true){
        if(b==a) break;
        l++;
        sum2+=b;
        b%=m;
        b*=b;
        b%=m;
    }
    //l++;
    k=k-l;
    if(zero==0){
        cout << sum << endl;
        return 0;
    }
    ll t=(n-l)/k;
    ll u=(n-l)%k;
    //t++;
    sum=sum-sum2;
    sum*=t;
    //a=x;
    for(int i=0;i<u;i++){
        sum+=a;
        a%=m;
        a*=a;
        a%=m;
    }
    sum=sum+sum2;
    cout << sum << endl;
    return 0;
}