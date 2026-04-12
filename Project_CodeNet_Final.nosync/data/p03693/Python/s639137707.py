r, g, b = map(int, input().split())

# rgbを、100の位・10の位、1の位の順に表示
# 4の倍数の場合は「YES」、そうじゃない時は「NO」
if (100 * r + 10 * g + b) % 4 == 0:
    print("YES")
else:
    print("NO")