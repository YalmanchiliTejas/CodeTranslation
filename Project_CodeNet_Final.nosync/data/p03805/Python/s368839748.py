n,m=map(int,input().split())
e=[[]for _ in[0]*-~n]
for _ in[0]*m:
    a,b=map(int,input().split())
    e[a]+=[b]
    e[b]+=[a]
candy=[[1]]
for _ in[0]*~-n:
    tmp=[]
    for c in candy:
        for next in e[c[-1]]:
            tmp+=[c+[next]]
    candy=tmp
print(sum(c==set(range(1,n+1))for c in map(set,candy)))