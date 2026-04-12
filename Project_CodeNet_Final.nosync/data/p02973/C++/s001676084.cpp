#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
bool cmp(int a,int b)
{
        return a>b;
}
int main()
{
        int N,temp,ans=0,minone,one = 0;
        cin>>N;
        for(int i=0;i<N;i++)
        {
                scanf("%d",&temp);

                if(i==0)
                {
                        vec.push_back(temp);
                        minone = temp;
                        ans++;
                }
                else
                {
                        if(temp<=minone)
                        {
                                vec.push_back(temp);
                                minone = temp;
                                one++;
                                ans++;
                        }
                        else
                        {
                                for(int i=0;i<=one;i++)
                                {
                                        if(vec[i]<temp)
                                        {
                                                vec[i] = temp;
                                                if(i==one)      minone = temp;
                                                break;
                                        }
                                }
                        }
                }

                //sort(vec.begin(),vec.end(),cmp);

        }
        cout<<ans<<endl;
}
