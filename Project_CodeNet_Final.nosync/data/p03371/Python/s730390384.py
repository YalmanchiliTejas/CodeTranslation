# coding: utf-8

# https://atcoder.jp/contests/abc095/tasks/arc096_a
# 16:32-16:44


def main():
    a, b, c, x, y = map(int, input().split())

    if y > x:
        a, b, x, y = b, a, y, x
    # aの方が枚数（x)多い

    ans = 0
    if a+b > 2*c:
        ans += 2*c*y

        if a > 2*c:
            ans += 2*c*(x-y)
        else:
            ans += a*(x-y)
    else:
        ans += a*x + b*y

    return ans


print(main())
