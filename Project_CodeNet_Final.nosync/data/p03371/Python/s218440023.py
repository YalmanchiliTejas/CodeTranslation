a, b, c, x, y = map(int, input().split())
#if a+b <= 2*c:  # aとbをそのまま買う
#    print(a*x + b*y)
#else:
#    if a >= 2*c and b >= 2*c:  # 全部ABピザにする
#        print(2*c * max(x, y))
#    else:
#        if x >= y:
#            print(2*c*y + a*(x-y))
#        else:
 #           print(2*c*x + b*(y-x))


ans = 0

if a+b <= 2*c:
    ans += (a+b) * min(x, y)
else:
    ans += 2*c * min(x, y)

if x >= y:
    if a >= 2*c:
        ans += 2*c*(x-y)
    else:
        ans += a*(x-y)
else:
    if b >= 2*c:
        ans += 2*c*(y-x)
    else:
        ans += b*(y-x)

print(ans)


# 10100 100 500 10 0