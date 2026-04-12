a = [int(s) for s in input().split()]
b = a[1]
c = [b]
d = {b:0}
flag = int(0)
k = int(0)
t = int(0)
m = int(0)
suma = int(0)
sumb = int(0)
cnt = int(0)
newc = []
newnewc = []

for i in range(1, a[0]):
    b = (b ** 2) % a[2]
    if d.get(b) == None:
        d[b] = i
        c.append(b)
    else:
        flag = 1
        sumb = sum(c)
        k = int(c.index(b))
        newc = c[k:]
        suma = sum(newc)
        k = len(newc)
        t = i
        m = (a[0] - t) % k
        break

if flag == 1:
    newnewc = newc[:m]
    print((a[0] - t) // k * suma + sumb + sum(newnewc))
else:
    print(sum(c))
