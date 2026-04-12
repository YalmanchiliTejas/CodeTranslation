n = int(input())
a = sorted(int(input()) for _ in range(n))
m = n // 2
if n % 2 == 0:
    ans = (sum(a[m:]) - sum(a[:m])) * 2 - a[m] + a[m-1]
    print(ans)
else:
    ans1 = (sum(a[m+1:]) - sum(a[:m])) * 2 - a[m] + a[m-1]
    ans2 = (sum(a[m+1:]) - sum(a[:m])) * 2 - a[m+1] + a[m]
    print(max(ans1, ans2))