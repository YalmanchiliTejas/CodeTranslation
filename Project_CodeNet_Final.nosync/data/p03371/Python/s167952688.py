def resolve():
    a, b, c, x, y = map(int, input().split())
    if a+b > c*2:
        com = min(x, y)
        if x >= y:
            if a > 2*c:
                ans = 2*c*x
            else:
                ans = 2*c*com + (x-y)*a
        else:
            if b > 2*c:
                ans = 2*c*y
            else:
                ans = 2*c*com + (y-x)*b
    else:
        ans = a*x + b*y

    print(ans)

if __name__ == '__main__':
    resolve()