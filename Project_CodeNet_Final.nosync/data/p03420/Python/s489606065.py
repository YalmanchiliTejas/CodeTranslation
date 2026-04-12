n,k = map(int,input().split())
ans = 0
for b in range(1,n+1):
    p = n//b
    q = n%b
    ans += max(b-k,0)*p
    ans +=max(0,q-k+1)
    if k==0:ans-=1
    
print(ans)
    