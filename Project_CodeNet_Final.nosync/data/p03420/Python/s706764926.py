n,k = map(int,input().split())
if(k==0):
    print(n*n)
    exit()
ans = 0
for i in range(k+1,n+1):
    ans += (n//i) * (i-k)
    ans += max(0, n%i-k+1)
print(ans)