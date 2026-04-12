n,x = map(int,input().split())
dp_a=[1]
dp_p=[1]
for i in range(1,n):
  dp_a.append(2*dp_a[i-1] + 3)
  dp_p.append(2*dp_p[i-1] + 1)  
  
def burger(n,x):
  if n==0:
    if x <= 0:      
      return 0
    else:
      return 1
    
  if x <= dp_a[n-1]+1:
    return burger(n-1, x-1)
  else:
    return dp_p[n-1] +1 +burger(n-1, x-dp_a[n-1]-2)  

print(burger(n,x))