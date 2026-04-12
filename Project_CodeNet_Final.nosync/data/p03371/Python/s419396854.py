def main():
    a, b, c, x, y = (int(i) for i in input().split())
    ans = a*x + b*y
    cur = 2*c*min(x, y) + (a*(x-y) if x > y else b*(y-x))
    ans = min(ans, cur)
    cur = 2*c*max(x, y)
    ans = min(ans, cur)
    print(ans)


if __name__ == '__main__':
    main()
