import sys
L = input()
s1,s2 = raw_input(),raw_input()
l1,l2 = len(s1), len(s2)

if l1 == l2:
  print( min(s1,s2) * (L//l1) )
  sys.exit()

cands = []
n1 = 0
while True:
  if (L - n1*l1) % l2 == 0:
    n2 = (L - n1*l1) // l2
    cands.append(s1*n1 + s2*n2)
    cands.append(s2*n2 + s1*n1)
    break
  n1 += 1

n2 = 0
while True:
  if (L - n2*l2) % l1 == 0:
    n1 = (L - n2*l2) // l1
    cands.append(s1*n1 + s2*n2)
    cands.append(s2*n2 + s1*n1)
    break
  n2 += 1

print(min(cands))