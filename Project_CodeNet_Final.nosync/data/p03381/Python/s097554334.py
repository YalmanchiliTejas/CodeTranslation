def main():
    n = int(input())
    x = list(map(int, input().split()))
    s = sorted(x)
    m1 = s[n // 2 - 1]
    m2 = s[n // 2]
    for i in x:
        if i < m2:
            print(m2)
        else:
            print(m1)


if __name__ == '__main__':
    main()
