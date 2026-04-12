#!/usr/bin/env python

def main():
    a, b, c, x, y = map(int, input().split())
    ab = c * 2

    i = min(x, y)
    if ab < a + b:
        pay = ab * i
    else:
        pay = a * i + b * i
    x -= i
    y -= i

    if x != 0:
        if ab < a:
            pay += ab * x
        else:
            pay += a * x
    elif y != 0:
        if ab < b:
            pay += ab * y
        else:
            pay += b * y

    print(pay)

if __name__ == '__main__':
    main()
