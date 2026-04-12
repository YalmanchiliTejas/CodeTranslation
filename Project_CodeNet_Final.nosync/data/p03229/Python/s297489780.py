n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
ans = 0

if n%2 == 0:
    ans = 2*(sum(a[n//2:])-sum(a[:n//2]))+a[n//2-1]-a[n//2]
else:
    ans = 2*(sum(a[n//2+1:])-sum(a[:n//2]))
    ans -= min(a[n//2+1]-a[n//2], a[n//2]-a[n//2-1])
print(ans)
