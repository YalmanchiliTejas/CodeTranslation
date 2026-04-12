n = int(input())
h = list(map(int,input().split()))
ans = 1
max_h = 0
for i in range(1,n):
    if h[0] <= h[i] and max_h <= h[i] and h[i] >= h[i-1]:
        ans += 1

    max_h = max(h[i],max_h)

print(ans)