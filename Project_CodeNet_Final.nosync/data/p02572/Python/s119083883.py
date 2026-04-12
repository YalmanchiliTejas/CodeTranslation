import numpy as np
from numba import njit, i8
import sys
read = sys.stdin.readline
mod = 10 ** 9 + 7


@njit((i8, i8[:]), cache=True)
def main(n, a):
    s = np.zeros(n + 1, dtype=np.int64)
    for i in range(n):
        s[i + 1] = (a[i] + s[i]) % mod
    ans = 0
    for i in range(1, n):
        ans = (ans + a[i] * s[i] % mod) % mod
    print(ans)


n = int(read())
a = np.fromstring(read(), dtype=np.int64, sep=' ')
main(n, a)
