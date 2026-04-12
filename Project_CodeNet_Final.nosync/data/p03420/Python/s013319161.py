n, k = map(int, input().split())

if k == 0:
    ans = n**2
    print(ans)
    exit()

ans = 0
for b in range(1, n+1):
    if b <= k:
        continue
    q, r = divmod(n, b)
    if r < k:
        ans += ((b-1)-k+1)*q
    else:
        ans += ((b-1)-k+1)*q + r-k+1
print(ans)
