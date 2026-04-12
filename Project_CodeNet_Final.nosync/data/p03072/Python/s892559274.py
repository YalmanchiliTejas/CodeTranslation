n = int(input())
h = list(map(int, input().split()))

ans = 1
o = h[0]
for i in range(1, len(h)):
    o = max(o, h[i])
    if h[i] >= o:
        ans += 1

print(ans)