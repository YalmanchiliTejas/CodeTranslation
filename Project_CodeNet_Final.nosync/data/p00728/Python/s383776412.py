import math
while True:
    n=int(input())
    if n==0:
        break
    l=[]
    for i in range(n):
        l.append(int(input()))
    slist=sorted(l)
    del slist[0]
    del slist[n-2]
    x=sum(slist)/len(slist)
    print(math.floor(x))
    



