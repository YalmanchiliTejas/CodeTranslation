import sys
read = sys.stdin.read
readlines = sys.stdin.readlines
large_p = 10**9 + 7
from itertools import accumulate
def main():
    n, *a = map(int, read().split())
    a2 = [ae % large_p for ae in a]
    a2a = tuple(accumulate(a2))
    r = 0
    for i1 in range(n - 1):
        t0 = a2[i1] * (a2a[-1] - a2a[i1])
        r += t0
        r = r % large_p
    print(r)

if __name__ == '__main__':
    main()