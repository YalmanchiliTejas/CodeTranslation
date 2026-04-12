def main():
    a, b, c, x, y = (int(i) for i in input().split())
    ans = 0
    if x > y:
        p = (x - y)*a
    elif y > x:
        p = (y - x)*b
    else:
        p = 0
    print(min(a*x + b*y, 2*c*max(x, y), 2*c*min(x, y) + p))


if __name__ == '__main__':
    main()
