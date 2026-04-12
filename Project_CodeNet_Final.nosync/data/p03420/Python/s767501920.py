n, k = map(int, input().split())

ans = 0
for b in range(max(1,k), n+1):
    ans += n//b * max(0, b-k) + max(0, n%b+1-k)
    if k == 0: ans -= 1

print(ans)
