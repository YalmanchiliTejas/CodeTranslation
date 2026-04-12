def main():
    n = int(input())
    a = [int(an) for an in input().split()]
    divider = 10 ** 9 + 7
    ans = 0
    total = sum(a)
    tmp = 0
    for i in range(n - 1):
        ai = a[i]
        tmp += ai
        ans = (ans + a[i] * (total - tmp)) % divider
    print(ans)


if __name__ == '__main__':
    main()
