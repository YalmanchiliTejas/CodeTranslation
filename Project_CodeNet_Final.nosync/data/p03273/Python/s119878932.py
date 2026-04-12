import sys
z = []
x = list(map(int, input().split()))
s = [list(input()) for i in range(x[0])]
h = x[0]
w = x[1]
l = []
y = []
# 横
for i in range(0, h):
  for j in range(0, w):
    if s[i][j] == '#':
      y.append(s[i])
      break

t = []
# 縦
# 縦横逆にする
for j in range(0, len(y[0])):
  for i in range(0, len(y)):
    l.append(y[i][j])
  t.append(l)
  l = []

p = []
for i in range(0, len(t)):
  for j in range(0, len(t[i])):
    if t[i][j] == '#':
      p.append(t[i])
      break
u = []
for j in range(0, len(p[0])):
  for i in range(0, len(p)):
    l.append(p[i][j])
  u.append(l)
  l = []
for i in u:
  print(''.join(i))