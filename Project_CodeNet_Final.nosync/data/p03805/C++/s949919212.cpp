#include<iostream>
#include<vector>
using namespace std;

int count=0;


void permute(vector<int>a,int index,vector<vector<int>>edges){
    
    if(index==a.size())
    {
        bool no=false;
        for(int i=0;i<a.size()-1;i++)
        {
            if(edges[a[i]][a[i+1]]==false)
            {
                no=true;
                break;
            }
        }
        if(!no){
            count++;
        }
        return;
    }
    for(int i=index;i<a.size();i++)
    {
        int temp=a[i];
        a[i]=a[index];
        a[index]=temp;
        permute(a,index+1,edges);
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;
    }
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(n,vector<int>(n,false));
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a-1][b-1]=true;
        edges[b-1][a-1]=true;
    }
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back(i);
    }
    permute(arr,1,edges);
    cout<<count;
}