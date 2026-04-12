n,k=map(int,input().split())
a=0
for b in range(k+1,n+1):
  a+=(b-k)*(n//b)+(n%b-k+1)*(n%b>k-1)-1*(k==0)
print(a)
