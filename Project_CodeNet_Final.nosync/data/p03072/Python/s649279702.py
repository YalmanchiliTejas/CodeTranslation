#B
n = int(input())
h = list(map(int, input().split()))

ans = 1
max = h[0]

for i in range(1, n):
    # print(i)
    if max <= h[i]:
        ans += 1
        max = h[i]
    # print(h[i], max)
print(ans)