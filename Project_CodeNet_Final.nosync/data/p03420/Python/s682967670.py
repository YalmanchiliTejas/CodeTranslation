def main():
    n, k = map(int, input().split())
    if k == 0:
        print(n * n)
        return
    c = 0
    for b in range(k + 1, n + 1):
        c += n // b * (b - k) + max(n % b - k + 1, 0)
    print(c)


if __name__ == '__main__':
    main()
