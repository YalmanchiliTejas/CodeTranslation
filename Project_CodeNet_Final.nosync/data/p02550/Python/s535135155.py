FAST_IO = 0
if FAST_IO:
    import io, sys, atexit
    rr = iter(sys.stdin.read().splitlines()).next
    sys.stdout = _OUTPUT_BUFFER = io.BytesIO()

    @atexit.register
    def write():
        sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
else:
    rr = raw_input
rri = lambda: int(rr())
rrm = lambda: map(int, rr().split())
rrmm = lambda n: [rrm() for _ in xrange(n)]

####
MOD = 998244353
YES, NO, IMP = "YES", "NO", "IMPOSSIBLE"
from collections import defaultdict as ddic


def solve(N, X, M):
    seen = {X: 0}
    t = 0
    while True:
        t += 1
        if t == N:
            return sum(seen)
        X2 = X*X%M
        if X2 not in seen:
            seen[X2] = t
            X = X2
            continue
        break

    base = sum(seen)
    N -= t
    u = seen[X2]
    mu = t - u
    period = sum(k for k,v in seen.items() if v >= u)
    Q, R = divmod(N, mu)
    #print("YO", base, N, u, mu, period, Q, R, ';', X)
    
    base += Q * period

    X = X2
    while R:
        base += X
        X *= X
        X %= M
        R -= 1

    return base

def brute(N, X, M):
    A = [X]
    while len(A) < N:
        A.append(A[-1] ** 2 % M)
    #print(A)
    
    return sum(A)
#N, X, M = 3,2,7
#print(brute(N,X,M))
#ans = solve(N,X,M)
#print ans

if 0:
    for n in xrange(1, 100):
        for x in xrange(1, 10):
            for m in xrange(x + 1, 100):
                if solve(n,x,m) != brute(n,x,m):
                    print("!", n,x,m, ';',solve(n,x,m), brute(n,x,m))
                    break
            
print solve(*rrm())
