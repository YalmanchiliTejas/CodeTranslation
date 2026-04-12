import math
inf=float('inf')
N = int(input())
x = list(map(int, input().split()))
y = [0]*(N)
j=0
for i in range(0,N,1):
    
    if i%2==0:
        y[j]=x[N-1-i]
  
    if i%2==1:
        y[N-1-j]=x[N-1-i]
        j+=1
    
    


for i in range(len(y)):
    print(y[i],end=' ')
 
quit()