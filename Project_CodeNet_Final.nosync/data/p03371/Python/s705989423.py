a,b,c,x,y = map(int, input().split())

#a,b別々
ans = a * x + b * y

#全てabで作る
ans = min(ans, c * 2 * max(x,y))

if x - y > 0:
    # 残りをaで買う
    t = c * 2 * y
    t += a * (x - y)
    ans = min(ans, t)
else:
    # 残りをbで買う
    t = c * 2 * x
    t += b * (y - x)
    ans = min(ans, t)
print(ans)
