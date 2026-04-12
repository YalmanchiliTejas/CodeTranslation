#!python3

import sys
iim = lambda: map(int, sys.stdin.readline().rstrip().split())

def resolve():
    mod = 10**9 + 7
    it = map(int, sys.stdin.read().split())
    N = next(it)
    A = list(it)

    ans,  sm = 0, A[-1]
    for i in reversed(range(N-1)):
        ans = (ans + A[i] * sm) % mod
        sm = (sm + A[i]) % mod
    print(ans % mod)

if __name__ == "__main__":
    resolve()
