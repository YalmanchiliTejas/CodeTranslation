a, b, c, x, y = map(int, input().split())
z = max(x, y)
ans = float('inf')
#ABピザの枚数をiとする
for i in range(0, 2 * z + 1, 2):
    #合計費用
    total = a * max(0, (x - (i // 2))) + b *max(0, (y - (i // 2))) + c * i
    ans = min(ans, total)
print(ans)