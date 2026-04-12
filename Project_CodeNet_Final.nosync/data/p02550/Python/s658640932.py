n, x, m = map(int, input().split())

s = set()
l = [x]
while x ** 2 % m not in s:
    v = x ** 2 % m
    s.add(v)
    l.append(v)
    x = v

idx = l.index(x ** 2 % m)
loop = len(l) - idx

if n < len(l):
    print(sum(l[:n]))
elif (n - idx) % loop == 0:
    print(sum(l[:idx]) + ((n - idx) // loop) * sum(l[idx:]))
else:
    print(sum(l[:idx]) + ((n - idx) // loop) * sum(l[idx:]) + sum(l[idx:idx+(n-idx)%loop]))