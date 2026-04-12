import sys
from collections import Counter

def main():
    input = sys.stdin.readline
    n = int(input())

    S1 = str(input().strip())
    c = Counter(S1)
    chrs = list(c.keys())

    for _ in range(n-1):
        s = str(input().strip())
        c_tmp = Counter(s)

        for chr_ in chrs:
            c[chr_] = min(c[chr_], c_tmp[chr_])

    ans = ''
    for chr_ in chrs:
        ans += chr_ * c[chr_]

    return ''.join(sorted(ans))


if __name__ == '__main__':
    print(main())
