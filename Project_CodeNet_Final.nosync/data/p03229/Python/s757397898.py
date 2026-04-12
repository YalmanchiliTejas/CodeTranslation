N=int(input())
l=list(int(input()) for i in range(N))
l.sort()
m=l[:]
a=b=l.pop(0)
ansA=0
for i in range(0,len(l)):
    if i%4==0:
        ansA+=l[-1]-a
        c=l.pop(-1)
    elif i%4==1:
        ansA+=l[-1]-b
        d=l.pop(-1)
    elif i%4==2:
        ansA+=c-l[0]
        a=l.pop(0)
    else:
        ansA+=d-l[0]
        b=l.pop(0)
c=d=m.pop(-1)
ansB=0
for i in range(0,len(m)):
    if i%4==2:
        ansB+=m[-1]-a
        c=m.pop(-1)
    elif i%4==3:
        ansB+=m[-1]-b
        d=m.pop(-1)
    elif i%4==0:
        ansB+=c-m[0]
        a=m.pop(0)
    else:
        ansB+=d-m[0]
        b=m.pop(0)
print(max([ansA,ansB]))