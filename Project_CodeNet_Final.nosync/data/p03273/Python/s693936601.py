H,W=(int(i) for i in input().split())
L=[]
for i in range(H):
    L.append(list(input()))

for x in L[:]:
    if '#' in x:
        continue
    else:
        L.remove(x)
L=list(map(list,zip(*L)))
for x in L[:]:
    if '#' in x:
        continue
    else:
        L.remove(x)
        
L=list(map(list,zip(*L)))
for i in range(len(L)):
    print(''.join(L[i]))