import sys

stdin = sys.stdin
def ns(): return stdin.readline().rstrip()
def ni(): return int(stdin.readline().rstrip())
def nm(): return map(int, stdin.readline().split())
def nl(): return list(map(int, stdin.readline().split()))


def main():
    n = ni()
    A = nl()
    mod = 10 ** 9 + 7
    s = sum(A)
    q = sum([a ** 2 for a in A])
    ans = (((s * s) - q)) // 2
    print(int(ans % mod))


if __name__ == '__main__':
    main()
