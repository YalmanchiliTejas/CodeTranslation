l = list(map(int, input().split()))

sum = 0
a = b = c = 0

if l[0] > l[2]*2 or l[1] > l[2]*2:
    c1 = c2 = 0
    if l[0] > l[2]*2:
        c1 = 2 * l[3]
    if l[1] > l[2]*2:
        c2 = 2 * l[4]
    c = max([c1, c2])
elif l[0]+l[1] > l[2]*2:
    c += min([l[3], l[4]])*2
else:
    a = l[3]
    b = l[4]


if a+c/2 < l[3]:
    a += l[3]-(c/2+a)
if b+c/2 < l[4]:
    b += l[4]-(c/2+b)

sum = a*l[0] + b*l[1] + c*l[2]

print(int(sum))
