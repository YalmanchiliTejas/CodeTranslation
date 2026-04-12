H,W=map(int,input().split())
a=[list(map(str, input())) for _ in range(H)]

c=[]
for li in a:
    if li!=['.']*len(li):
        c.append(li)

b=[]
for lc in zip(*c):
    if lc!=('.',)*len(lc):
        b.append(lc)

for ld in zip(*b):
    print(''.join(ld))




