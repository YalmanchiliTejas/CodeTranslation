mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    S = 0
    T = 0
    for a in A:
        S = (S + a)%mod
        T = (T + (a*a)%mod)%mod
    print(((((S * S)%mod - T)%mod) * pow(2, mod-2, mod))%mod)


if __name__ == '__main__':
    main()
