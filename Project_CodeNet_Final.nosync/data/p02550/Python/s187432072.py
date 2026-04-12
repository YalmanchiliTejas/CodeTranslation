n, x, m = list(map(int, input().split()))

r = [0] * (m)

r[x] = 1
a = x

t = 0
u = 0

s = [0, x]

for i in range(2, m+2):

    a = (a ** 2) % m
    s.append(s[-1] + a)

    if r[a] == 0:
        r[a] = i
    else:
        t = i - r[a]
        u = r[a]
        break

if u >= n:
    print(s[n])

else:
    #print(s, t, u)
    p = (n - (u-1)) // t
    q = (n - (u-1)) % t

    ans = s[u-1+ q] + p * (s[u+t] - s[u])

    print(ans)