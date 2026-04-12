n = int(input())
h = list(map(int, input().split()))
max = h[0]
ans = 0
for i in range(n):
    if h[i]>=max:
        max = h[i]
        ans += 1
print(ans)