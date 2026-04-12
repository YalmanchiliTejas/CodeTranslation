n = int(input())
h = list(map(int, input().split()))
ans = 1
high = h[0]

for i in range(1, n):
    if h[i] > high:
        high = h[i]
    diff = h[i] - high
    if diff >= 0:
        ans += 1
print(ans)