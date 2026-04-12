n = int(input())
h = list(map(int, input().split()))
high = h[0]
ans = 1
for i in range(1,n):
    if high <= h[i]:
        ans += 1
        high = h[i]

print(ans)