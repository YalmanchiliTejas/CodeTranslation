def main():
    x, y, z = map(int, input().split())

    p = 0
    length = 0
    while length <= x:
        p += 1
        length = y * p + z * (p + 1)

    print(p - 1)


if __name__ == '__main__':
    main()
