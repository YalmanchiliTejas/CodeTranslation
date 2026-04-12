import numpy as np
h,w=map(int,input().split())
t=[list(input()) for _ in range(h)]
for i in range(h):
    t[i]=[(tij=="#")*1 for tij in t[i]]
t=np.array(t,dtype="i2")
rows=[]
columns=[]
for i in range(h):
    if np.sum(t[i])==0:
        rows+=[i]
for j in range(w):
    if np.sum(t[:,j])==0:
        columns+=[j]
t=np.delete(t,rows,0)
t=np.delete(t,columns,1)
for i in range(h-len(rows)):
    print(*["#" if tij else "." for tij in t[i]],sep="")
