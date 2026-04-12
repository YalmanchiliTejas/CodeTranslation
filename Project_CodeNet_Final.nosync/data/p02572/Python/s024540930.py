def main():
    n = int(input())
    # d,t,s = map(int, input().split())
    a = list(map(int, input().split()))
    # s = input()
    mod = 10**9+7

    s = sum(a)

    sm = 0

    for i in a:
        s -= i
        sm += i * s % mod

    print(sm % mod)


if __name__ == '__main__':
    main()
