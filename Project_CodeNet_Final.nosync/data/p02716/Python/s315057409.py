n = int(input())
a = list(map(int, input().split()))

le, lo, re, ro = [0], [0], [0], [0]

for i in range(n):
    if i % 2 == 0:
        le.append(le[-1] + a[i])
    else:
        lo.append(lo[-1] + a[i])

for i in range(n-1, -1, -1):
    if i % 2 == 0:
        re.append(re[-1] + a[i])
    else:
        ro.append(ro[-1] + a[i])

le_o = [0]
for i in range(len(lo)-1):
    le_o.append(max(0, le_o[-1] + a[2*i+1] - a[2*i]))


if n % 2 == 0:
    n //= 2
    ans = lo[n]
    for i in range(0, n + 1):
        ans = max(ans, le[i] + ro[n-i])

    print(ans)

else:
    n //= 2
    ans = le[n]
    for i in range(0, n+1):
        ans = max(ans, le[i] + ro[n-i])
        ans = max(ans, lo[i] + re[n-i])
        ans = max(ans, le[i] + re[n-i] + le_o[i])

    print(ans)
