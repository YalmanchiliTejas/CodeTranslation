import sys
d1 = {}
l = []
while True:
  a,b = input().split(',')
  if (a,b) == ('0','0'):
    break
  else:
    d1[a] = int(b)
    if (int(b) not in l):
      l.append(int(b))
l.sort()
l.reverse()
for line in sys.stdin.readlines():
  n = line.replace('\n','')
  print(l.index(d1[n])+1)