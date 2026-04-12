n,k = map(int,input().split())
ans = 0
for i in range(1,n+1):
    p,r = divmod(n, i)
    ans += p*max(0,i-k)+max(0,r-k+1)
print(ans if k != 0 else ans - n)