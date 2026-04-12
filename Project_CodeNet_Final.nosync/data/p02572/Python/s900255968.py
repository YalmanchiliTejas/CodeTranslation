N=int(input())
ans=0

A=list(map(int,input().split()))
zentai=sum(A)
ruiseki_WA=[]
kasu=0
for i in range(N):
    kasu+=A[i]
    ruiseki_WA.append(kasu)
hako=sum(A)
for i in range(N):
    ans+=A[i]*(hako-ruiseki_WA[i])   
print(ans%(10**9+7)) 