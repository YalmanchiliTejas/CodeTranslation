n = int(input())
h = [int(i) for i in input().split()]
maxi = 0
ans = 0
for i in range(n):
    if maxi <= h[i]:
        ans += 1
        maxi = h[i]
print(ans)
