#include <cstdio>

int main(){
        int n;

        while( scanf("%d", &n) , n ){
                int count = 0;
                int* a;
                a = new int[n*n];
				for(int i=0 ; i<n ; i++){
					for(int j=0 ; j<n ; j++){
                                a[i*n+j] = 0;
					}
				}
                int x = n/2;
                int y = n/2 + 1;
                count++;
                a[y*n+x] = count;
                while(count<n*n){
                        y = (y+1)%n;
                        x = (x+1)%n;
                        if(a[y*n+x]==0){
                                count++;
                                a[y*n+x] = count;
						}else{
							y = (y+1)%n;
							x = (x-1+n)%n;
							if(a[y*n+x]==0){
                                count++;
                                a[y*n+x] = count;
							}
						}
                }
                for(int i=0 ; i<n ; i++){
                        for(int j=0 ; j<n ; j++){
                                printf("%4d", a[i*n+j]);
                        }
                        printf("\n");
                }
        }

        return 0;
}