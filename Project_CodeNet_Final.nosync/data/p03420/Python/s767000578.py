n, k = map(int, input().split())
ans = 0
if k == 0:
    print(n ** 2)
    exit()
for b in range(k+1,n+1):
    lmax = n // b
    ans += (b - k) * lmax
    t = n % b
    ans += max(0, t - k + 1)
print(ans)