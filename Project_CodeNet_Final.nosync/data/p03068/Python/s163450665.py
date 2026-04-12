N=int(input())
S=input()
K=int(input())
s=S[K-1]
L=[]
for i in range(N):
    if s!=S[i]:
        L.append('*')
    else:
        L.append(s)
print(*L,sep='')