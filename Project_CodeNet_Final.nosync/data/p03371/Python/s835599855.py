def main():
    a, b, c, x, y = (int(i) for i in input().split())
    ans1 = a * x + b * y
    ans2 = -1
    if x < y:
        ans2 = 2 * c * x + b * (y - x)
    else:
        ans2 = 2 * c * y + a * (x - y)
    ans3 = 2 * c * max(x, y)
    print(min(ans1, ans2, ans3))


if __name__ == '__main__':
    main()
