a, b, c, x, y = list(map(int, input().split()))
nokori_x, nokori_y = x, y
cost = 0
count_a, count_b, count_c = 0, 0, 0

# まず、AとBのセットを最安の方法で買う
# AとBのセットは何個あるか？
ab_set_n = min(x, y)
if ab_set_n:
    if c * 2 < (a + b):
        # Cを買ったほうがお得
        cost += c * 2 * ab_set_n
    else:
        cost += (a + b) * ab_set_n

# セットにできるものはしたので、
# どちらもゼロ、あるいはAかBの片方だけが残っているはず
nokori_n = max(x, y) - ab_set_n
if nokori_n:
    price = a if max(x, y) == x else b
    if c * 2 < price:
        cost += c * 2 * nokori_n
    else:
        cost += price * nokori_n

print(cost)
