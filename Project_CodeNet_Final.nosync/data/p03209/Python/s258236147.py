n,x=map(int,input().split())
pati_kazu=[1]
atsusa=[1]
for i in range(n):
    pati_kazu.append(pati_kazu[i]*2+1)
    atsusa.append(atsusa[i]*2+3)

def dfs(level,z):
    if level==0:
        return 0 if z<=0 else 1
    elif z<=(1+atsusa[level-1]):
        return dfs(level-1,z-1)
    else:
        return 1+pati_kazu[level-1]+dfs(level-1,z-2-atsusa[level-1])

print(dfs(n,x))