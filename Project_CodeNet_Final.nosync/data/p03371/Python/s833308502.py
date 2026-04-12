# AtCoder Beginner Contest 095
# C - Half and Half
# https://atcoder.jp/contests/abc095/tasks/arc096_a

a, b, c, x, y = map(int, input().split())

if a + b <= 2*c:
    print(a*x+b*y)
else:
    z = min(x, y)
    ans = 2*c*z
    x -= z
    y -= z

    if x == 0:
        if b < 2*c:
            ans += b*y
        else:
            ans += 2*c*y
    else:
        if a < 2*c:
            ans += a*x
        else:
            ans += 2*c*x
    
    print(ans)