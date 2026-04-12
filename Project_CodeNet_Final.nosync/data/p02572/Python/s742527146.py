import numpy as np
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
mod = 10 ** 9 + 7


def main():
    ans = 0
    cs = np.cumsum(np.array(a))
    for i in range(n-1):
        s = (cs[-1] - cs[i]) % mod
        ans = (ans+(a[i]*int(s)) % mod) % mod
    return ans


n, *a = map(int, read().split())
a = main()
print(a)
