from itertools import product

N = int(input())
S = input()


def r(x):
    if x == 'S':
        return 'W'
    else:
        return 'S'


def f(x1, x2, s):
    if s == 'o':
        if x1 == 'S':
            return x2
        else:
            return r(x2)
    else:
        if x1 == 'S':
            return r(x2)
        else:
            return x2


ans = ['-1']
for x1, x2 in product('SW', repeat=2):
    res = [x1, x2]
    for i in range(N):
        x1, x2 = x2, f(x1, x2, S[i])
        res.append(x2)
    if res[:2] == res[-2:]:
        ans = res[1:-1]
        break
print(''.join(ans))
