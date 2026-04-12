h,w = map(int,input().split())
l = []
for i in range(h):
    l.append([x for x in input()])

for i in range(h-1,-1,-1):
    if "#" not in l[i]:
        del l[i]
z = list(zip(*l))

for i in range(len(z)-1,-1,-1):
    if "#" not in z[i]:
        for j in range(len(l)):
            del l[j][i]
            
for i in range(len(l)):
    print("".join(l[i]))