#include<bits/stdc++.h>
using namespace std;
//long long a[100005]={0};
vector<long long>a;
vector<long long>q1;
vector<long long>q2;
vector<long long>q3;
vector<long long>q4;
vector<long long>q5;
int main()
{
	long long n,m,c;
	cin>>n;
	for(int i=0;i<n;i++)
	{int t;
		cin>>t;
		a.push_back(t);
	}
	if(n==1)
	{
		printf("0\n");
		
	}
	
	sort(a.begin(),a.end());
	long long sum=0,mid=n/2;

       
       vector<long long>q;
    
       if(n%2==1)
       {    
	       q.push_back(a[mid]);
	       q2.push_back(a[mid]);
	      //long long dise=a[n-1]-a[mid],disb=a[mid]-a[0];
        	   for(long long i=0;i<n/2;i++)
                {
                	q.push_back(a[n-1-i]);
       	      	    q.push_back(a[i]);	
	            }
             
          
            for(long long i=0;i<n/2;i++)
           { q2.push_back(a[i]);
       	    q2.push_back(a[n-1-i]);
       	    		
	        }
	
	     	   
	   }
	   else
	   { mid--;
	   	   q4.push_back(a[mid]);
	     
        
	           for(long long i=0;i<n/2-1;i++)
                {
                	q4.push_back(a[n-1-i]);
       	      	    q4.push_back(a[i]);	
	            }
	            q4.push_back(a[mid+1]);
             
           q3.push_back(a[mid]);
            for(long long i=0;i<n/2-1;i++)
           { q3.push_back(a[i]);
       	    q3.push_back(a[n-1-i]);
       	    		
	        }
	q3.push_back(a[mid+1]);
	     	
		 mid++;
		    q1.push_back(a[mid]); 
		      q5.push_back(a[mid]);
		     //long long dise1=a[n-1]-a[mid],disb1=a[mid]-a[0];
		     	   for(long long i=0;i<n/2-1;i++)
                {
                	q1.push_back(a[n-1-i]);
       	      	    q1.push_back(a[i]);	
	            }
	            q1.push_back(a[mid-1]);
             
          
            for(long long i=0;i<n/2-1;i++)
           { q5.push_back(a[i]);
       	    q5.push_back(a[n-1-i]);
       	    		
	        }
	q5.push_back(a[mid-1]);
	     //printf(" 11");
	   }
	   
     long long ans[10]={0};
     long long sum1=0;
	   for(long long i=0;i<n-1;i++)
	   {
	   	if(n%2==1)
	   	{
	   		ans[0]+=abs(q[i]-q[i+1]); 
	   		ans[1]+=abs(q2[i]-q2[i+1]); 
		   }
	   	else
	   	{
	   	ans[2]+=abs(q1[i]-q1[i+1]); 
	   	ans[3]+=abs(q3[i]-q3[i+1]); 
	   		sum1+=abs(q4[i]-q4[i+1]); 
	   			ans[5]+=abs(q5[i]-q5[i+1]); 
		   }

		} 
		sort(ans,ans+6);
	//	
	
cout<<ans[5]<<endl;	
 } 