import sys

N,M = map(int,input().split())
if M == 0:
  print('No')
  sys.exit()
if N/M == 1:
  print('Yes')
else:
  print('No')