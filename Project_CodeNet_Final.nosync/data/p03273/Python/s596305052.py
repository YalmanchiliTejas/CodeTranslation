h,w=map(int, input().split())
a=[input() for _ in range(h)]
ta=[]
tb=[]
tc=[]
for x in a:
    j=False
    for y in x:
        if y=='#':
            j=True
    if j:
        ta.append(x)
for i in range(1,w+1):
    t=[ta[j][-i] for j in range(len(ta))]
    j=False
    for x in t:
        if x=='#':
            j=True
    if j:
        tb.append(t)
for i in range(len(tb[0])):
    t=[tb[-j][i] for j in range(1,len(tb)+1)]
    print("".join(t))