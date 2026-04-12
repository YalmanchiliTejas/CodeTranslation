n,k = list(map(int,input().split()))
ans = 0
for i in range(k+1,n+1):
    ans += (n//i)*(i-k)+max(n%i-k+1,0)
if k==0: ans-=n
print(ans)
