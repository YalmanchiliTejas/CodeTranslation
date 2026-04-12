n = int(input())
h = [int(i) for i in input().split()]
ans = 1
mx = h[0]
for hi in h[1:]:
    if hi >= mx:
        # print(hi)
        ans += 1
    mx = max(mx, hi)

print(ans)
