n, k = map(int, input().split())
ans = 0
for i in range(1, n+1):
    tmp1 = max(0, n//i * (i-k))
    tmp2 = max(n%i+1-k, 0)
    ans += tmp1 + tmp2

if k != 0:  
    print(ans)
else:
    print(n**2)
