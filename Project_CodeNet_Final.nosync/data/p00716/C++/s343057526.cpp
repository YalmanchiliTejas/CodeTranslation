#include<iostream>
#include<algorithm>

using namespace std;

int rieki(bool ri,double riritu,int kingaku, int kikan,int tesuu){
    int risi=0;
    if(ri){
        for(int i=0;i<kikan;i++){
            kingaku=kingaku*(1+riritu)-tesuu;
        }
    }else{
        for(int i=0;i<kikan;i++){
            risi+=kingaku*riritu;
            kingaku-=tesuu;
        }
    }
    return kingaku+risi;
}

int main(){
    int m;
    cin>>m;
    for(int j=0;j<m;j++){
        int kane,nen;
        cin>>kane>>nen;
        int n;
        cin>>n;
        int ans=0;
        for(int k=0;k<n;k++){
            bool r;
            double riri;
            int te;
            cin>>r>>riri>>te;
            ans=max(rieki(r,riri,kane,nen,te),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}