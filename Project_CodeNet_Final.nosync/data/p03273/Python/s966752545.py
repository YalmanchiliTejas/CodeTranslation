h, w = map(int, input().split())

ll = [list(input()) for _ in range(h)]
lh = [h for h in ll if '#' in h]
lw = zip(*[w for w in zip(*lh) if '#' in w])

for l in lw:
  print(''.join(l))