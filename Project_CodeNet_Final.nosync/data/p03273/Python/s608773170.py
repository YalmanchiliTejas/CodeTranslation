a, b = map(int, input().split())
L = [input() for _ in range(a)]
L1 = []
L3 = []
for i in range(a):
  if not L[i] == "."*b:
    L1.append(L[i])
L2 = list(map(list, zip(*L1)))
for k in range(len(L2)):
  if not "".join(L2[k]) == "."*len(L2[k]):
    L3.append("".join(L2[k]))
L4 = list(map(list, zip(*L3)))
for v in range(len(L4)):
  print("".join(L4[v]))