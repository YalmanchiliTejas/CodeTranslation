N = int(input())
h = [int(i) for i in input().split()]

_max = 0
ans = 0
for i in range(N):
    if _max <= h[i]:
        _max = h[i]
        ans+=1
print(ans)