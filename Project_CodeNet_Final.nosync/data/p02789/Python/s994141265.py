import sys
a, b = [int(x) for x in sys.stdin.readline().rstrip('\n').split()]
if a == b:
  print('Yes')
else:
  print('No')