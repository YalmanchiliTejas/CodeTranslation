# ABピザを使うんなら効率的に使う、をやるとO(1)
a, b, c, x, y = map(int, input().split())
t = (x - y) * a if x > y else (y - x) * b
# 順に、ABピザを「使わない」「一部使う（必要枚数が少ないほうに合わせる。不足するピザはそのピザだけを買う）」「全部使う（必要枚数が多い方に合わせる。あまったピザ上等）」
print(min(a * x + b * y, 2 * c * min(x, y) + t, 2 * c * max(x, y)))
