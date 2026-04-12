def main():
    a, b, c, x, y = (int(i) for i in input().split())
    ans = a*x + b*y
    ans = min(ans, 2*c*max(x, y))
    if x < y:
        d = y - x
        d *= b
    else:
        d = x - y
        d *= a
    ans = min(ans, 2*c*min(x, y)+d)
    print(ans)


if __name__ == '__main__':
    main()
