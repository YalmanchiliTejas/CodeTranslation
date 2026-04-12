n = int(input())
h = list(map(int,input().split()))
max = 0
ans = 0
for i in range(n):
    if max <= h[i] :
        ans += 1
        max = h[i]
print(ans)
