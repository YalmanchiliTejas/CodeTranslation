def main(n, h):
    base = 0
    count = 0

    for _h in h:
        if _h >= base:
            base = _h
            count += 1

    print(count)


if __name__ == "__main__":
    n = int(input())
    h = list(map(int, input().split(' ')))

    main(n, h)

