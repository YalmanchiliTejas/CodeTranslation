n, x, m = map(int, input().split())
a = [0] * (pow(10, 5) + 5)
b = [0] * (pow(10, 5) + 5)
c = [0] * (pow(10, 5) + 5)
for i in range(1, m + 1):
    if x == 0:
        ans = c[i - 1]
        break
    if a[x] == 0:
        a[x] = i
        b[i] = x
        c[i] = c[i - 1] + b[i]
        x = (x ** 2) % m
    else:
        if i >= n:
            ans = c[n]
        else:
            ans = c[i - 1]
            n -= (i - 1)
            s, t = a[x] - 1, i - 1
            ans += (c[t] - c[s]) * (n // (t - s))
            n %= (t - s)
            ans += (c[s + n] - c[s])
        break
print(ans)