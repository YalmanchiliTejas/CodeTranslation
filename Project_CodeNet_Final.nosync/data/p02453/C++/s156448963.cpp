#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    int len_array,num_query;
    int key;
    scanf("%d",&len_array);
    vector<int> int_array(len_array);
    for(int i = 0;i < len_array;i++){
        cin >> int_array[i];
    }
    
    scanf("%d",&num_query);
    for(int i = 0;i < num_query;i++){
        scanf("%d",&key);
        vector<int>::iterator itr = lower_bound(int_array.begin(),int_array.end(),key);
        cout << itr - int_array.begin() << "\n";
    }
    
    return 0;
}
