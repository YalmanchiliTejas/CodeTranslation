N, X, M = map(int, input().split())
if X == 0:
    print(0)
    exit()
tx = X % M
tl = []
ts = set()
ttl = []
for i in range(N):
    tl.append(tx)
    ts.add(tx)
    tx = pow(tx, 2, M)
    if tx in ts:
        ttl = tl[tl.index(tx):]
        break
ans = sum(tl)
if len(ttl)>0:
    d, m = divmod(N-len(tl), len(ttl))
    ans += sum(ttl)*d+sum(ttl[:m])
print(ans)
