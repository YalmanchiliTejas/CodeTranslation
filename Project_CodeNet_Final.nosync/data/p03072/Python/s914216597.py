n = int(input())
h = list(map(int, input().split()))

num = 0
ans = 0

for i in range(n):
    if h[i]>=num:
        ans += 1
        num = h[i]

print(ans)