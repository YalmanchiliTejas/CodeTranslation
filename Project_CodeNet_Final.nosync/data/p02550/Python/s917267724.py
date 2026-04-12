import sys
input = sys.stdin.readline
N, X, M = map(int, input().split())
table = [0] * M
c = [0] * M
c[X] = 1
x = X
while table[x] <= 1:
  table[x] += 1
  if c[x ** 2 % M] == 0: c[x ** 2 % M] = c[x] + 1
  x = x ** 2 % M
loop = table.count(2)
#print(loop)
res = 0
for x in range(M):
  if c[x] in range(1, N + 1):
    res += x
    if c[x] + loop in range(1, N + 1) and (table[x] >= 2): res += x * ((N - c[x]) // loop)
print(res)