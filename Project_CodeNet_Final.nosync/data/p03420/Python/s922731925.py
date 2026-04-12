n,k=input().split()
n,k=int(n),int(k)
if k==0:
    print(n*n)
else:
    res=n*k
    for i in range(k+1,n+1):
        res+=n//i*k+min(n%i,k-1)
    print(n*n-res)