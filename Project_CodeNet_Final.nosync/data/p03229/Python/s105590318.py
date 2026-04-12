n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
ans = 0
if n % 2 == 0:
    ans = sum(a[n//2+1:])*2 + a[n//2] - sum(a[:n//2-1])*2 - a[n//2-1]
elif n % 2 == 1:
    ans1 = sum(a[n//2+2:])*2 + a[n//2] + a[n//2+1] - sum(a[:n//2])*2
    ans2 = sum(a[n//2+1:])*2 -sum(a[:n//2-1])*2 -a[n//2] - a[n//2-1]
    ans = max(ans1,ans2)
print(ans)