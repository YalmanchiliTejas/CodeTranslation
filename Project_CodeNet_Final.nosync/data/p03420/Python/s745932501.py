n,k = map(int, input().split())

if k == 0:
    print(n*n)
    exit()

ans = 0
for b in range(k+1,n+1):
    ans += (b-k) * (n//b)
    if b*(n//b)+k<=n:
        ans += n-(b*(n//b)+k-1)

print(ans)
