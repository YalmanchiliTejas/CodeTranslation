import sys

S = str(input())

before = S[0]
for s in S:
   if s != before:
      print('Yes')
      sys.exit()
   before = s

print('No')