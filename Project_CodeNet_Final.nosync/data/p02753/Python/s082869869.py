def map_all(es):
    return all([e == es[0] for e in es[1:]]) if es else False

a =input()
aa = list(a)

if map_all(aa):
  print('No')
else:
  print('Yes')
