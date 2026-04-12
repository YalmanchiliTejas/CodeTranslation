n = int(input())
h = list(map(int, input().split()))

ans = 1
max_n = h[0]
for i in range(1,n):
    if max_n <= h[i]:
        max_n = h[i]
        ans += 1

print(ans)