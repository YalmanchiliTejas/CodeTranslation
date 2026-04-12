#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
        int a[200001];
        vector <int> b;
        int N;
        cin>>N;
        for(int i=0;i<N;i++){
                cin>>a[i];
        }
        for(int i=0;i<N;i++){
                if(i%2==0)
                        b.push_back(a[i]);
                else
                        b.insert(b.begin(), a[i]);
        }
        if(N%2==1){
                reverse(b.begin(), b.end());
        }
        for(int i=0;i<N;i++){
                cout<<b[i];
                if(i!=N-1)cout<<" ";
                else cout<<endl;
        }
        return 0;
}
