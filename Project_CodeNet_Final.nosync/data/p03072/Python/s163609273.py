n = int(input())
hs = list(map(int, input().split()))
ss = []

for i in range(n):
  b = False
  for j in range(i):
    if hs[j] > hs[i]:
      b = True
  if not b:
    ss.append(i)
print(len(ss))