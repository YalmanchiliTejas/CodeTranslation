s = int(input())
k = list(input())
l = int(input())

char = k[l-1]
for i in range(s):
  if k[i] != char:
    k[i] = '*'

print(''.join(k))