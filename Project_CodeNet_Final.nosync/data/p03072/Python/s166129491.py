n = int(input())
h = list(map(int,input().split()))
ans = 1
m = h[0]
for i in range(n-1):
    if h[i] <= h[i+1] and h[i+1] >= m:
        ans += 1
        m = h[i+1]
print(ans)