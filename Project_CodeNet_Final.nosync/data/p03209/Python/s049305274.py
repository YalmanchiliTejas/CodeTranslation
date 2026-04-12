import sys
readline = sys.stdin.readline

N, X = map(int,readline().split())

T = [0] * (N + 1) # レベルiバーガーの厚さ
P = [0] * (N + 1) # レベルiバーガーのパティの数

T[1] = 5
P[1] = 3

for i in range(2, N + 1):
  T[i] = T[i - 1] * 2 + 3
  P[i] = P[i - 1] * 2 + 1

# Nバーガー,X枚目
stack = [[N,X]]
ans = 0

while stack:
  n, x = stack.pop()
  if n == 1:
    ans += min(x - 1,3)
    continue
  if x <= 1: # 1枚目の場合はパティなし
    continue
  if x < 1 + T[n - 1]: # 一つ目のレベルn - 1バーガーに収まる場合
    stack.append([n - 1, x - 1])
  elif x <= 1 + T[n - 1]:
    ans += P[n - 1]
  elif x == 2 + T[n - 1]:
    ans += P[n - 1]
    ans += 1
  elif x < 2 + T[n - 1] * 2:
    ans += P[n - 1]
    ans += 1
    stack.append([n - 1, x - (T[n - 1] + 2)])
  else:
    ans += P[n - 1] * 2
    ans += 1

print(ans)