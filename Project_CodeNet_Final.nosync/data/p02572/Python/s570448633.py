def main():
    input()
    mod = 10**9 + 7
    ar = sorted(map(int, input().split()))
    ar.reverse()

    cnt = ar[0] + ar[1]
    an = ar[0] * ar[1] % mod

    for i in range(2, len(ar)):
        an += cnt * ar[i]
        cnt += ar[i]

    print(an % mod)


if __name__ == '__main__':
    main()