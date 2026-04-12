def main(n, m):
    if n == m:
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    n, m = map(int, input().split())

    main(n, m)
