 #include <bits/stdc++.h>
using namespace std;
 
int main() {
    int h,w,cnt=0;
    cin>>h>>w;
    string a[100];
    for(int i=0;i<h;++i)
        cin>>a[i];
    for(int i=0;i<h;++i)
    {   
        for(int j=0;j<w;++j)
        {
            if(a[i][j] == '#')
                cnt++;
        }
    }
    if(cnt==h+w-1)
        cout<<"Possible"<<endl;
    else 
        cout<<"Impossible"<<endl;
    return 0;
    
}