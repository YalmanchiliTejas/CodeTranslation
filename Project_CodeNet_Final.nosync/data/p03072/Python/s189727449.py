n = int(input())

h = list(map(int, input().split()))

ans = 1

high = h[0]

for i in range(1, n):
    if high <= h[i]:
        ans += 1
        high = h[i]


print(ans)
