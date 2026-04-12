import sys
s = input()
for x, y in zip(s, s[1:]):
  if x == 'A' and y == 'C':
    print('Yes')
    sys.exit()
print('No')