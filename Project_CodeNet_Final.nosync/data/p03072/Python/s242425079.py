n = int(input())
hs = map(int, input().split())
ans = 0
buf = 0
for h in hs:
    if h >= buf:
        ans += 1
        buf = h
print(ans)
