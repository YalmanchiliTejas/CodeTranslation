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
from collections import defaultdict as ddic, Counter, deque
import heapq, bisect, itertools
MOD = 10 ** 9 + 7

N = rri();A=rrm()

S = sum(A)
S %= MOD
ans = S*S % MOD
for x in A:
    ans -= x*x % MOD
    ans %= MOD
ans *= pow(2, MOD-2, MOD)
ans %= MOD
print ans
