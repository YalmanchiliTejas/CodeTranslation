n = int(input())
h = list(map(int, input().split()))

curr = 0
ans = 0
for i in range(n):
    if h[i] >= curr:
        ans += 1
        curr = h[i]
print(ans)