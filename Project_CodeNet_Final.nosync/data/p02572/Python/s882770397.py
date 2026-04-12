import sys

if sys.subversion[0] == "PyPy":
    import io, atexit

    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))

    sys.stdin = io.BytesIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()
RS = raw_input
RA = lambda x=int: map(x, RS().split())
RN = lambda x=int: x(RS())


def solve():
    m = 10 ** 9 + 7
    s = sum(a) % m
    ans = 0
    running = 0
    for i in range(n):
        running += a[i]
        ans += (a[i] * (s - running))
        ans %= m
    ans %= m
    print(ans)
    return



n = RN()
a = RA()
solve()
