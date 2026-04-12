import sys
readline = sys.stdin.readline

N,X = map(int,readline().split())

# レベルNバーガーの厚さ = (レベルN - 1バーガーの厚さ) * 2 + 3
# レベル1〜Nの厚さを先に求めておく

T = [1] * (N + 1)
for i in range(1, len(T)):
  T[i] = T[i - 1] * 2 + 3

# レベルNバーガーをX枚目まで食べたとき、パティを何枚食べるか
# レベルN - 1バーガーの厚さをtとする
# X = 1 : 0枚
# X <= t + 1 : レベルN - 1バーガーのX - 1枚目まで
# X = t + 2 : レベルN - 1バーガーのt枚目まで + 1
# X < t * 2 + 3 : レベルN - 1バーガーのすべてと、1枚と、レベルN - 1バーガーのX - (t + 2)枚目まで
# X = t : レベルN - 1バーガーのすべて * 2 + 1

def bargar(n,x):
  if n == 1:
    return min(x - 1, 3)
  t = T[n - 1] # レベルNバーガーの厚さ
  if x == 1:
    return 0
  elif x <= t + 1:
    return bargar(n - 1, x - 1)
  elif x == t + 2:
    return bargar(n - 1, t) + 1
  elif x < t * 2 + 3:
    return bargar(n - 1,t) + 1 + bargar(n - 1, x - (t + 2))
  else:
    return bargar(n - 1,t) * 2 + 1

print(bargar(N,X))