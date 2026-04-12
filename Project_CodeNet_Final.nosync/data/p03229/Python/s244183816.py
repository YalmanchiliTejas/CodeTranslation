n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a.sort()
if n%2==0:
    ans = -2*sum(a[:n//2])
    ans += 2*sum(a[n//2:])
    ans += a[n//2-1] - a[n//2]
else:
    ans = -2*sum(a[:n//2])
    ans += 2*sum(a[n//2+1:])
    ans += max(a[n//2-1]-a[n//2], a[n//2]-a[n//2+1])
print(ans)