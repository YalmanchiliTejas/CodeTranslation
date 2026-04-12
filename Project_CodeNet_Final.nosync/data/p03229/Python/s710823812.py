n = int(input())
a = [int(input()) for _ in range(n)]
a.sort(reverse=True)

ans = 0
if n % 2 == 0:
    plus = a[:n//2]
    minus = a[n//2:]
    ans = (2*sum(plus)-plus[-1]) - (2*sum(minus)-minus[0])
else:
    ans1 = 0
    plus = a[:n//2]
    minus = a[n//2:]
    ans1 = (2*sum(plus)) - (2*sum(minus)-minus[0]-minus[1])

    ans2 = 0
    plus = a[:(n+1)//2]
    minus = a[(n+1)//2:]
    minus.sort()
    ans2 = (2*sum(plus)-plus[-1]-plus[-2]) - (2*sum(minus))

    ans = max(ans1, ans2)

print(ans)