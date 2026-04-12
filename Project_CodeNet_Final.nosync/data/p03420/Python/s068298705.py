n,k=map(int,input().split())
a=0
for i in range(k+1,n+1):a+=max(0,n%i+1-k)+(i-k)*(n//i)
print(n**2if not k else a)