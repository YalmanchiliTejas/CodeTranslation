h,w=map(int,input().split())
m=[]
for _ in range(h):
    l=input()
    if '#' in l:
        m.append(l)
m=list(zip(*m))
n=[]
for i in m:
    if '#' in i:
        n.append(i)
n=list(zip(*n))
for i in n:
    for j in i:
        print(j,end='')
    print('')
