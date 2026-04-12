h, w = map(int, input().split())
rs = [input() for _ in range(h)]
rows = []

#.だけの行を省いてrowsに格納
for r in rs:
  if '#' in r: rows.append(r)

ansrows = zip(*[c for c in zip(*rows) if '#' in c])

for r in list(ansrows):
  print(''.join(r))