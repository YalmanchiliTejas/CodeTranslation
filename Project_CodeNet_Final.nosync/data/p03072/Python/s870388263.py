n = int(input())
hl = [ int(x) for x in input().split() ]

k = 0
ans = 0
for h in hl:
    if h >= k:
        ans += 1
        if h > k:
            k = h

print(ans)