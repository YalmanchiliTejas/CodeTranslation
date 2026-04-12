import itertools

N,M=map(int,input().split())
S=[list(map(int,input().split()))for _ in range(M) ]

a=[]
for i in range(N):
    a.append(i+1)

L=list(itertools.permutations(a))


cnt=0

for l in L:
    tmp=1
    if l[0]!=1:
        break
    for j in range(N-1):
        if ([l[j],l[j+1]] in S) or ([l[j+1],l[j]] in S):
            tmp=1
        else:
            tmp=0
            break
    if tmp==1:
        cnt+=1

print(cnt)