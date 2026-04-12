n,k = map(int,input().split())
ans = 0
for i in range(k+1,n+1):
    x = n//i
    ans += x*(i-k)
    ans += max(0,n%i-max(1,k)+1)
print(ans)