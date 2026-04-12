n=int(input())
S=tuple(map(int,input().split()))
ans=0
for c in range(1,n-1):
    k=1
    tmp=0
    while c*k<n-1:
        a=n-1-k*c
        if a<=c or (a<=k*c and a%c==0):
            break
        tmp+=S[n-1-k*c]+S[k*c]
        k+=1
        ans=max(ans,tmp)
print(ans)