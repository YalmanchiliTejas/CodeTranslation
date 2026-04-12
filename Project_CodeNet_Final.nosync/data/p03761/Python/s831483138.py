N=int(input())

#S = [[0 for j in range(3)] for i in range(2)]　2行3列の場合
S = [[] for i in range(N)]
for i in range(N):
    tmp=input()
    for j in range(len(tmp)):
        S[i].append(tmp[j])
    S[i].sort()

T=S[0]
for i in range(N):
    if len(T)>len(S[i]):
        T=S[i]


D=[]
for i in range(len(T)):
    tmp=T[0]
    flag=True
    for j in range(N):
        if tmp in S[j]:
            S[j].remove(tmp)
        else:
            flag=False
    if flag==True:
        D.append(tmp)

Z=[str(a) for a in D]
Z="".join(Z)
print(Z)
