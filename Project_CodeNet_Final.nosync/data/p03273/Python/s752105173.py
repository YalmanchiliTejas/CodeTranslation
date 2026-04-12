h,w=map(int,input().split())
t=[list(input()) for _ in range(h)]
for i in range(h):
    t[i]=[(tij=="#")*1 for tij in t[i]]
rows=[]
columns=[]
for i,ti in enumerate(t):
    if sum(ti)==0:
        rows+=[i]
for j,tj in enumerate(zip(*t)):
    if sum(tj)==0:
        columns+=[j]
nt=[]
for i,ti in enumerate(t):
    if i in rows:continue
    nti=[]
    for j,tij in enumerate(ti):
        if j in columns:continue
        nti+=["#" if tij else "."]
    print(*nti,sep="")
