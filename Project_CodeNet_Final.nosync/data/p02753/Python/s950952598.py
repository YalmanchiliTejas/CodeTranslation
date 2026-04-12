import sys

s = list(input())
if s[0] == 'A' and s[1] == 'A' and s[2] == 'A':
  print('No')
  sys.exit()
if s[0] == 'B' and s[1] == 'B' and s[2] == 'B':
  print('No')
  sys.exit()
print('Yes')