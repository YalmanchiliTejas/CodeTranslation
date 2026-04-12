n = int(input())
a = []
for i in range(n):
    a += [int(input())]
a.sort()
n2 = n // 2

if n % 2:
    ans1 = (sum(a[n2 + 1:]) - sum(a[:n2 + 1])) * 2 + a[n2] + a[n2 - 1]
    ans2 = (sum(a[n2:]) - sum(a[:n2])) * 2 - a[n2] - a[n2 + 1]
    ans = max(ans1, ans2)
else:
    ans = (sum(a[n2:]) - sum(a[:n2])) * 2 - a[n2] + a[n2 - 1]

print(ans)
