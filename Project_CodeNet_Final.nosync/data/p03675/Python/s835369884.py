n=int(raw_input())
N=map(int,raw_input().split())
a=[]
b=[]
for i in range(n):
    if i%2==0:
        a.append(N[i])
    else:
        b.append(N[i])
if n%2==0:
    b.reverse()
    for i in b+a:
        print i,
else:
    a.reverse()
    for i in a+b:
        print i,
