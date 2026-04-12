# utf-8:
def main():
    x, y, z = map(int, raw_input().split())
    a = y + z
    b = x - z
    n = 0

    while True:
        if (n * a) <= b:
            n += 1
        else:
            break

    print(n-1)


if __name__ == '__main__':
    main()
