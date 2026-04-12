import sys
s = input()

for i in range(2):
  for j in range(1, 3):
    if s[i] != s[j]:
      print('Yes')
      sys.exit()

print('No')