n = int(input())
h = list(map(int,input().split()))

ans = 0
max_ = 0
for i in range(n):
    if max_ <= h[i]:
        max_ = h[i]
        ans += 1

print(ans)