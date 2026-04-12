import numpy as np

n=int(input())
S=[]
for i in range(0,n):
    s=str(input())
    S.append(s)
SSS=''
alpha=list('abcdefghijklmnopqrstuvwxyz')
c=np.zeros((n,26))
for i in range(0,26):
    for j in range(0,n):
        c[j,i]=S[j].count(alpha[i])
    if np.min(c[:,i])>0.5:
        SSS=SSS+alpha[i]*int(np.min(c[:,i]))
print(SSS)