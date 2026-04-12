n = int(input())
h =[int(x) for x in input().split()]

max = 0
ans = 0
for i in range(n):
    if max <= h[i]:
        max  = h[i]
        ans = ans + 1
print(ans)