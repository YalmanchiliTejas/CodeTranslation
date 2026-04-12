n = int(input())

a = []

for i in range(n):
    a.append(int(input()))

a.sort(reverse=True)

ans = 0
if n % 2 == 1:
    ans1 = 0
    for i in range(n):
        if i <= n // 2:
            ans1 += 2 * a[i]
            if i == (n // 2) or (i == n // 2 - 1):
                ans1 -= a[i]
        else:
            ans1 -= 2 * a[i]

    ans2 = 0
    for i in range(n):
        if i < n // 2:
            ans2 += 2 * a[i]
        else:
            if i == (n // 2) or (i == n // 2 + 1):
                ans2 -= a[i]
            else:
                ans2 -= 2*a[i]

    ans = max(ans1, ans2)

else:
    ans = 0
    for i in range(n):
        if i < n // 2:
            if i==(n//2-1):
                ans += a[i]
            else:
                ans += 2*a[i]
        else:
            if i== n//2:
                ans -= a[i]
            else:
                ans -=2*a[i]

print(ans)
