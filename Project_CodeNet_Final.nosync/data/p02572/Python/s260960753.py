import sys
read = sys.stdin.read
readlines = sys.stdin.readlines
from itertools import accumulate
def main():
    n, *a = map(int, read().split())
    large_p = 10 ** 9 + 7
    aac = tuple(accumulate(a))
    r = 0
    for i1 in range(n):
        t1 = aac[-1] - aac[i1]
        r += (t1 * a[i1]) % large_p
    r = r % large_p
    print(r)


if __name__ == '__main__':
    main()
