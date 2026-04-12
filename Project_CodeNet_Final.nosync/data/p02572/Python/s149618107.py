import sys
si = sys.stdin.readline


def main():
    n = int(si())
    l = [int(e) for e in si().split()]
    tot = sum(l)
    mod, ans = 10**9+7, 0
    for i in range(n-1):
        h = l[i]
        tot -= h
        ans = (ans+(tot*h) % mod) % mod
    print(ans)


if __name__ == '__main__':
    main()
