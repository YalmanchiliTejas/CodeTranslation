n, k = map(int, input().split())
ans=0
for b in range(k+1, n+1):
    q=n//b
    r=n%b
    if r<k:
        ans+=(q-1)*(b-k)
    else:
        ans+=(q-1)*(b-k)+(r-k+1)
if k>0:
    ans+=(n-k+1)*(n-k)//2
else:
    ans+=n*(n-1)//2
print(ans)