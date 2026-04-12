def main():
    a, b, c, x, y = (int(i) for i in input().split())
    v1 = 2*c*max(x, y)
    v2 = 2*c*min(x, y) + (y-x if x < y else x-y)*(b if x < y else a)
    v3 = a*x + b*y
    print(min(v1, v2, v3))


if __name__ == '__main__':
    main()
