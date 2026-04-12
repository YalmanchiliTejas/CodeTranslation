n, x, m  = map(int, input().split())
a = [x]
found = {x}
while True:
    y = (a[-1] ** 2) % m
    a.append(y)
    if y in found:
        break
    found.add(y)
if n <= len(a):
    print(sum(a[:n]))
else:
    z = a.index(a[-1])
    a.pop()
    n -= z
    res = sum(a[:z])
    res += sum(a[z:]) * (n // (len(a) - z))
    res += sum(a[z:z + (n % (len(a) - z))])
    print(res)
