import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def solve():
    N, X, M = map(int, input().split())

    if N == 1:
        print(X)
        return

    A = X
    steps = [0] * M
    sms = [0] * M
    steps[A] = 1
    sms[A] = A
    sm = A
    ans = A
    rest = 0
    for i in range(2, N+1):
        A = (A*A) % M
        sm += A
        ans += A
        if steps[A] != 0:
            P = i - steps[A]
            v = sm - sms[A]
            rest = N - i
            ans += v * (rest//P)
            rest %= P
            break
        steps[A] = i
        sms[A] = sm

    for i in range(rest):
        A = (A*A) % M
        ans += A

    print(ans)


solve()
