n=int(input())
x = list(map(int, input().split()))
total=0
t=sum(x)  
for i in range(n):
 
  t=t-x[i]
  total=total+x[i]*(t)
   
print(total %1000000007)
