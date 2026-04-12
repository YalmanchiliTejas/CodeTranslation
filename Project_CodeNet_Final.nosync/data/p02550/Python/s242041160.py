N, X, M = map(int, input().split())
loop = [X]
appeared = set(loop)
while True:
  n = loop[-1] ** 2 % M
  if n in appeared:
    break
  else:
    loop.append(n)
    appeared.add(n)
if N <= len(loop):
  print(sum(loop[:N]))
  exit()
  
i = loop.index(n)
preloop = loop[:i]
loop = loop[i:]

total = sum(preloop)
N -= len(preloop)
#print(total, N)
total += sum(loop) * (N // len(loop))
for l, _ in zip(loop, range(N % len(loop))):
  total += l
print(total)
