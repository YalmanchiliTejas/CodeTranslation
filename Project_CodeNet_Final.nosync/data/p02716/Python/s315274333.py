n = int(input())
a = list(map(int, input().split()))
k = n//2
d = dict()
d[(-2,0)] = 0
for i in range(n):
    nxt = dict()
    discard = []
    for (prev, cnt), score in d.items():
        if i-prev == 1:
            continue
        if cnt == k:
            continue
        nprev = i
        ncnt = cnt+1
        nscore = score+a[i]
        tmp = (nprev, ncnt)
        if tmp not in nxt or nxt[tmp] < nscore:
            nxt[tmp] = nscore
        r = n-1-i
        if cnt + (r+1)//2 < k:
            discard.append((prev, cnt))
    for key, value in nxt.items():
        d[key] = value
    for key in discard:
        d.pop(key)
ans = -float("inf")
for key, value in d.items():
    if key[1] == k:
        ans = max(ans, value)
print(ans)
