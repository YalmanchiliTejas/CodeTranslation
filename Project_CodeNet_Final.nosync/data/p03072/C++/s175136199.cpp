//#include<iostream>
//using namespace std;
//int apple[1000];
//int main(void)
//{
//    int n,d,cnt=0,t;
//    bool a=false;
//    cin >> n >> d;
//    t=1;
//    while(a==false){
//        t=t+d+1;
//        for(int i=t;i<=d+t;i++)
//            apple[i]=1;
//        cnt++;
//
//        int num=0;
//        for(int i=1;i<=n;i++)
//            if(apple[i]==1)
//                num++;
//        if(num==n)
//            a=true;
//    }
//    cout << cnt;
//    return 0;
//}
#include<iostream>
using namespace std;
int h[25];
int main(void)
{
    int n,num=0;
    cin >>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=2;i<=n;i++)
    {
        int num2=0;
        for(int j=1;j<i;j++)
            if(h[i]>=h[j])
                num2++;
        if(num2==i-1)
            num++;
    }
    cout<<num+1;
    return 0;
}