import sys


def main():
    a, b, c, x, y = map(int, input().split())

    min_price = None

    for i in range(max(x, y) + 1):
        nc = i * 2
        na = x - i
        if na < 0:
            na = 0
        nb = y - i
        if nb < 0:
            nb = 0

        price = na * a + nb * b + nc * c
        if min_price is None or price < min_price:
            min_price = price

    print(min_price)


if __name__ == '__main__':
    main()
