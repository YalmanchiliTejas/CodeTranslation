n = int(input())
h = list(map(int, input().split()))
hmax = h[0]
ans = 1
for hi in h[1:]:
    ans += hmax <= hi
    hmax = max(hmax, hi)
print(ans)
