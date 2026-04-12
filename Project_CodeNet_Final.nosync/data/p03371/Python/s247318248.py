def resolve():
    a, b, c, x, y = map(int, input().split())
    ans = 0
    if a+b > 2*c:
        com = min(x, y)
        ans += 2*c*com
        if x > y:
            if a >= 2 * c:
                ans += 2 * c * (x-com)
            else:
                ans += a * (x-com)
        elif x < y:
            if b >= 2 * c:
                ans += 2 * c * (y-com)
            else:
                ans += b * (y-com)
    else:
        ans += a*x + b*y

    print(ans)

if __name__ == '__main__':
    resolve()