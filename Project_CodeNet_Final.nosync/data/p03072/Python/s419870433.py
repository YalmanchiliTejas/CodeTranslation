n = int(input())
h = list(map(int, input().split()))
ans = 0
max = h[0]
for i in range(n):
    if max<=h[i]:
        ans += 1
        max = h[i]
print(ans)