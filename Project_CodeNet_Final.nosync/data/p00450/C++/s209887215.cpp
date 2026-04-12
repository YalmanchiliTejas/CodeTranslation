#include<cstdio>
#include<cstring>

using namespace std;

typedef struct{    
	int num;  
	int col; 
}STONE; 
int main(void){   
	int i,j;         
	int n;   
	int bw,temp;  
	int count;      
	int sum;         
	STONE data[100001]; 
	while(1){      
		scanf("%d", &n);   
		if (n==0){           
			break;     
		}       
		memset(data,0,sizeof(data));
		count=-1;    
		bw=2;         
		for(i=0;i<n;i++){          
			scanf("%d",&temp);        
			if(temp!=bw){            
				count++;             
				data[count].col=temp;         
				data[count].num=1;            
				bw=temp;                
			}else{                      
				data[count].num++;       
			}  
		}                 
		sum=0;           
		for(i=0;i<=count;i++){   
			sum+=data[i].num;    
			if((sum-data[i].num)%2==1){     
				j=i-1;                  
				while(j>=0 && data[j].col != data[i].col){      
					data[j].col^=1;                      
					j--;                              
				}                   
			}               
		}                  
		sum=0;              
		for(i=0;i<=count;i++){ 
			if (data[i].col==0){   
				sum+=data[i].num;      
			}         
		}             
		printf("%d\n",sum);         
	}             
	return 0; 
} 