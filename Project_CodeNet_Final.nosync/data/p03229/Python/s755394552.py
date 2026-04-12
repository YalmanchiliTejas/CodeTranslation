n = int(input())

a = []
for i in range(n):
    ai = int(input())
    a.append(ai)

a = sorted(a)

ans = 0

if n % 2 == 0:
    r = a[n//2-1]
    for i in range(n//2 - 1):
        q = a[-i-1]
        p = a[i]
        ans += abs(q-r) + abs(p-q)
        r = p
    ans += abs(r - a[n//2])

else:
    r = a[n//2]
    if r - a[n//2-1] < a[n//2+1] - r:
        for i in range(n//2):
            q = a[-i-1]
            p = a[i]
            ans += abs(q-r) + abs(p-q)
            r = p
    else:
        for i in range(n//2):
            q = a[i]
            p = a[-i-1]
            ans += abs(q-r) + abs(p-q)
            r = p

print(ans)

