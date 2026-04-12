a, b, c, x, y = map(int, input().split())

# 単体で買うより安い
if (a + b) > 2 * c:
    # 共通部分をABで買う方
    ans1 = c * min(x, y) * 2
    if x < y:
        ans1 += b * (y - x)
    else:
        ans1 += a * (x - y)
    
    # 余らせてでもABで買う方
    ans2 = c * max(x, y) * 2

    print(min(ans1, ans2))
else:
    ans = a * x + b * y 
    print(ans)