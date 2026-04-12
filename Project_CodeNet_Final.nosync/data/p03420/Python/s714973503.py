n,k=map(int,input().split())
c=0
for i in range(k+1,n+1):
  c+=n//i*(i-k)+max(0,n%i-k+int(k!=0))
print(c)
  