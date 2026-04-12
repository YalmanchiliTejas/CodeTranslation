n,x=map(int,input().split())
length=[0]*n;p=[0]*n
length[0]=1
p[0]=1
for i in range(1,n):
  length[i]=length[i-1]*2+3
  p[i]=p[i-1]*2+1
def meat(n,x):
  if n==0:
    return 0 if x<=0 else 1
  elif x<=1+length[n-1]:
    return meat(n-1,x-1)
  elif x==2+length[n-1]:
    return p[n-1]+1
  else:
    return p[n-1]+1+meat(n-1,x-length[n-1]-2)
print(meat(n,x))
