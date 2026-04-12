# 入力　文字列3つ
r, g, b = input().split()

# 並べた数字が4の倍数か
rgb = r + g + b

if int(rgb)%4 :
    print("NO")
else :
    print("YES")
