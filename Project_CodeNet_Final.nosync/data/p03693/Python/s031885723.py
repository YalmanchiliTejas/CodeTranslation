r, g, b = map(str, input().split())
#r,g,bを3桁の数xに変換
x = int(r + g + b)
if x % 4 == 0:
    print("YES")
else:
    print("NO")
