h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
b=[]
c=[]
#a = [x for x in a if "#" in x]
for x in a:
    if "#" in x:
        b.append(x)
#print(b)
bT = list(zip(*b))
#print(bT)
for x in bT:
    if "#" in x:
        c.append(x)
#print(c)
cT = list(zip(*c))
for i in cT:
    print("".join(i))