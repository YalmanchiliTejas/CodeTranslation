n, k = map(int, input().split())

ans = 0
for b in reversed(range(1, n+1)):
    if b == k:
        break
    y_cnt = b-k
    p, q = divmod(n, b)
    ans += y_cnt*p
    if k <= q:
        ans += q-max(k-1, 0)
print(ans)