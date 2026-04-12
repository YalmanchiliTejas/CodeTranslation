
def main():
    a, b, c, x, y = [int(i) for i in input().split()]

    y1 = a * x + b * y
    y2 = c * max(x, y) * 2
    if x >= y:
        y3 = c * y * 2
        y3 += a * (x - y)
    else:
        y3 = c * x * 2
        y3 += b * (y - x)
    print(min(y1, y2, y3))

if __name__ == '__main__':
    main()
