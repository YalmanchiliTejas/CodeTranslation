from itertools import permutations

N,M=map(int,input().split())
L=[]
for i in range(N-1):
    L.append(1+i)
A=[]
a=[]
for i in range(N):
    for j in range(N):
        a.append(10)
    A.append(a)
    a=[]
    
#print(A)

for i in range(M):
    a,b=map(int,input().split())
    A[a-1][b-1]=1
    A[b-1][a-1]=1

#print(A)
cnt=0
for i in permutations(L,len(L)):
    S=0
    for j in range(len(i)-1):
        if A[i[j]][i[j+1]]==10:
            break
        else:
            S+=1
    if S==len(L)-1:
        if A[0][i[0]]==1:
            cnt+=1
print(cnt)