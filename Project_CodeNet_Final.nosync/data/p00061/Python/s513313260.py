c=[]
d={}
while 1:
    a,b=map(int,input().split(','))
    if a==0:break
    c+=[b]
    d[a]=b
c=sorted(set(c))[::-1]
while 1:
    try:print(c.index(d[int(input())])+1)
    except:break