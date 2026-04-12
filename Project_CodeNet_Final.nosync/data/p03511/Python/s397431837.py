l = int(input())
a = input()
b = input()

if len(a) > len(b):
    k = b
    b = a
    a = k

mina = None
maxa = None
"""
f = [None] * (l + 1)

f[0] = ''
#print(f)
for i in range(l):
    tmpa = None
    tmpb = None
    if i + 1 >= len(a) and f[i + 1 - len(a)] is not None:
        tmpa = a + f[i + 1 - len(a)]
    if i + 1 >= len(b) and f[i + 1 - len(b)] is not None:
        tmpb = b + f[i + 1 - len(b)]
    if tmpa is None and tmpb is None:
        continue
    if tmpa is None and tmpb is not None:
        f[i+1] = tmpb
        continue
    if tmpb is None and tmpa is not None:
        f[i+1] = tmpa
        continue
    if tmpa < tmpb:
        f[i+1] = tmpa
    else:
        f[i+1] = tmpb
print(f[l])

def less(a, b):
    if a < b:
        if not b.startswith(a):
            return True
        else:
            c = b
            while c.startswith(a):
                c = c[len(a):]
            if a < c:
                return True
            else:
                return False

"""
for i in range(l+ 1) :
    if i * len(a) > l:
        break
    if (l - i * len(a)) % len(b) == 0:
        if mina is None:
            mina = i
            maxb = (l - i * len(a)) // len(b)
        maxa = i
        minb = (l - i * len(a)) // len(b)


ans1 = a * maxa + b * minb
ans2 = b * maxb + a * mina

if ans1 < ans2:
    print(ans1)
else:
    print(ans2)
