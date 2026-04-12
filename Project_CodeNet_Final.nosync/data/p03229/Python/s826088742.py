n = int(input())
a = sorted([int(input()) for _ in range(n)])
if n % 2:
    s = a[:n//2]
    t = a[n//2:]
    ans1 = 2*(sum(t)-sum(s))-t[0]-t[1]
    p = a[:n//2+1]
    q = a[n//2+1:]
    ans2 = 2*(sum(q)-sum(p))+p[-1]+p[-2]
    print(max(ans1, ans2))
else:
    s = a[:n//2]
    t = a[n//2:]
    ans = 2*(sum(t)-sum(s))-t[0]+s[-1]
    print(ans)

