n, k = map(int, input().split())

if k == 0:
    print(n**2)
    exit()

ans = 0
for i in range(1, n+1):
    if i <= k:
        continue
    q, r = divmod(n, i)
    if r < k:
        ans += (i-k)*q
    else:
        ans += (i-k)*q + (r-k+1)
print(ans)
