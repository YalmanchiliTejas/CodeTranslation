#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);
	int a[n], fr[n];
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	int col=0;
	fr[col]=a[0];
	int frmin=a[0];
	//int frminnum=0;	//colの番号
	col++;
	for(int i=1;i<n;i++){
		if(a[i]<=frmin){
			fr[col]=a[i];
			frmin=fr[col];
			//frminnum=i;
			col++;
		}else{
			for(int k=0;k<col;k++){
				if(fr[k]<a[i]){
					fr[k]=a[i];
					if(k==col-1){
                      	frmin=a[i];
                    }
                  	break;
				}
			}
		}
	}
	
	
	printf("%d", col);
	
	
	return 0;
}