n,k=map(int,input().split())
s=0
for i in range(k+1,n+1):
  s+=(n//i)*(i-k)
  s+=max(0,min(n%i,n%i-k+1))
print(s)