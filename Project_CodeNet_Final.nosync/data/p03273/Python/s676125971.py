from collections import Counter
H,W=map(int,input().split())
a=[list(str(input())) for i in range(H)]
b=[]
n_H=0
for l in a:
    c=Counter(l)
    if c['.']!=W:
        b.append(l)
        n_H+=1
d=[]
b=list(map(list,zip(*b)))
for l in b:
    c=Counter(l)
    if c['.']!=n_H:
        d.append(l)
d=list(map(list, zip(*d)))

for l in d:
    s=''.join(l)
    print(s)