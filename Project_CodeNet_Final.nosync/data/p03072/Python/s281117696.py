N = int(input())
Hlist = list(map(int, input().split()))
ans = 0
max_h = 0
for H in Hlist:
    if H >= max_h:
        ans += 1
    max_h = max(H, max_h)
print(ans)
