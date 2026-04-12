it = iter(open(0).read().split())
def reads(v):
    r = []
    for i in range(v):
        r.append(next(it).strip())
    return r
def read():
    return next(it).strip()


while 1:
    M, N = map(int, reads(2))
    if M == N == 0:
        break
    S = [1]*M; rest = M
    k = 0
    for i in range(1, N+1):
        s = read()
        if rest == 1:
            continue
        ok = 1
        if i % 15 == 0:
            if s != "FizzBuzz":
                ok = 0
        elif i % 3 == 0:
            if s != "Fizz":
                ok = 0
        elif i % 5 == 0:
            if s != "Buzz":
                ok = 0
        else:
            if s != str(i):
                ok = 0
        if not ok:
            S[k] = 0
            rest -= 1
        k = (k + 1) % M
        while not S[k]:
            k = (k + 1) % M
    print(*[i+1 for i in range(M) if S[i]])
