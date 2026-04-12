h,w=map(int,input().split())

l=[]
for i in range(h):
    a=input()
    if "#" in a:
        l.append(a)


r=[]
for i in range(w):
    for k in l:
        if k[i]=="#":
            r.append(i)
            break
n=len(l)
new_l=[]

for i in range(n):
    s=""
    for k in r:
        s=s+l[i][k]
    new_l.append(s)

for i in new_l:
    print(i)

