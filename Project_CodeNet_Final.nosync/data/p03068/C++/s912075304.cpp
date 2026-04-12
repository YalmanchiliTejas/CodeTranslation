    #include<bits/stdc++.h>
    #define mp make_pair
    #define pb push_back
    #define f first
    #define s second
    #define ll long long
    using namespace std;
    const int MAX =1e5+9;
    int main(){
    	int n;
    	string s;
    	cin>>n;
    	cin>>s;
    	int k;
    	cin>>k;
    	char c=s[k-1];
    	for(int i=0;i<n;i++){
    		if(c!=s[i])
    			cout<<'*';
    		else
    			cout<<s[i];
    	}
    	
    }