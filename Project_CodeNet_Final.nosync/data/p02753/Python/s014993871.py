import collections
S = list(input())
c = collections.Counter(S)


if 0 < c['A'] < 3:
  print('Yes')
else:
  print('No')
