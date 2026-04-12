N=input()
A=list(map(int,input().split()))
ans=0
for i in range(int(N)):
    B=0
    for j in range(i):
        if A[i]-A[j]>=0:
            B+=1
    if B==i:
        ans+=1
print(ans)