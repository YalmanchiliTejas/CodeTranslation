a,b,c,x,y = map(int,input().split())

ans = 0
# abがお得なパターン
if a + b >= c * 2:
    ans += c * min(x,y) * 2
    nokori = max(x,y) - min(x,y)
    # aが残ったパターン
    if max(x,y) == x:
        # abのがお得
        if a > c*2:
            ans += c * nokori * 2
        else:
            ans += a * nokori
    else:
        if b > c*2:
            ans += c * nokori * 2
        else:
            ans += b * nokori
else:
    ans += a * x + b* y

print(ans)

