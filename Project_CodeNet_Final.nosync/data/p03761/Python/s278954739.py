import collections

n=int(input())
S=collections.Counter(list(input()))
S0=list(S.items())
L=len(S0)
for i in range(L):
    S0[i]=list(S0[i])

for i in range(1,n):
    temp=list(input())
    for j in range(L):
        h=temp.count(S0[j][0])
        if h<S0[j][1]:
            S0[j][1]=h


ans=[]

for i in range(L):
    if S0[i][1]!=0:
        for j in range(S0[i][1]):
            ans.append(S0[i][0])

ans.sort()
print("".join(ans))

