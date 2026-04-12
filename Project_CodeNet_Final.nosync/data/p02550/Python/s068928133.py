import sys
read = sys.stdin.read
readlines = sys.stdin.readlines
from collections import defaultdict
def main():
    n, x, m = map(int, input().split())
    d1 = defaultdict(int)
    r = 0
    while n:
        if d1[x]:
            cycle = d1[x] - n
            t0 = 0
            cycle2 = cycle
            while cycle2:
                t0 += x
                x = x**2 % m
                cycle2 -= 1
            c, rem = divmod(n,  cycle)
            r += c * t0
            while rem:
                r += x
                x = x**2 % m
                rem -= 1
            print(r)
            sys.exit()
        else:
            d1[x] = n
            r += x
            x = x**2 % m
        n -= 1
    print(r)

if __name__ == '__main__':
    main()