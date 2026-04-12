N, X, M = map(int, input().split())

s = 0
mt = []
def f(x):
    return x**2 % M
i = 0
while True:
    i += 1
    mt.append(X)
    a = f(X)
    if i == N:
        f = 1
        break
    elif a in mt:
        f = 0
        break
    else:
        X = a

if f == 1:
    print(sum(mt))
else:
    e = mt.index(a)
    s1 = mt[:e]
    s2 = mt[e:]
    l = i - e
    c, d = divmod(N - e, l)
    print(sum(s1) + sum(s2) * c + sum(s2[:d]))