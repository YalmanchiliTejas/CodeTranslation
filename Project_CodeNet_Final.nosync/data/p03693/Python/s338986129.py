# 100の位r,10の位g,1の位ｂに整数を入力
r,g,b = map(int,input().split())
# 100r+10g+bが4の倍数ならYES、違うならNO
if (100 * r + 10 * g + b) % 4 == 0:
    print("YES")
else:
    print("NO")