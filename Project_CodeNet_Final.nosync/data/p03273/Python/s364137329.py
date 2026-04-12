h,w=map(int,input().split())
for i in zip(*[i for i in zip(*[i for i in [input() for i in range(h)] if '#' in i]) if '#' in i]):
  print(''.join(i))
