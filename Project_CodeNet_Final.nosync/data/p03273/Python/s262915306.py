H,W=map(int,input().split())

S=[""]*H

for i in range(H):
    S[i]=input()

isWw=[0]*W
isWh=[0]*H

for i in range(H):
    for k in range(W):
        if(S[i][k]=='#'):
            isWw[k]=1
            isWh[i]=1


for i in range(H):
    if(isWh[i]==0):
        continue
    for k in range(W):
        if(isWw[k]==1):
            print(S[i][k],end='')
    print()
