mod = 1000000007


def mul(a, b):
    return ((a % mod) * (b % mod)) % mod


def power(x, y):
    if y == 0:
        return 1
    elif y == 1:
        return x % mod
    elif y % 2 == 0:
        return power(x, int(y/2))**2 % mod
    else:
        return power(x, int(y/2))**2 * x % mod


def div(a, b):
    return mul(a, power(b, mod-2))


N = int(input())
A = list(map(int, input().split()))

s = int(0)
r = int(0)
for a in A:
    s = int(s + a)
    r = int(r + a * a)

print(div(s * s - r, 2))
