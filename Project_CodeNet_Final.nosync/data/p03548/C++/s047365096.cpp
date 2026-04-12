#include<iostream>
using namespace std;
int main()
{
    int chair_length,people_length,empty_length,answer=0;
    cin>>chair_length>>people_length>>empty_length;
    for(int i=empty_length+1; i<=chair_length-empty_length; i++)
    {
        if(i+people_length-1>=chair_length-empty_length+1) break;
        answer++;
        //cout<<"People "<<answer<<":"<<i<<endl;
        i+=(people_length-1);
        i+=empty_length;
    }
    cout<<answer<<endl;
    return 0;
}
