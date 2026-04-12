S = input()
L = []
for k in S:
    L.append(k)
newL = set(L)
if len(newL) == 1:
    print('No')
else:
    print('Yes')