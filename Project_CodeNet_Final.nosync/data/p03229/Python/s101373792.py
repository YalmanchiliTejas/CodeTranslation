N,*A=map(int, open(0).read().split())
A=sorted(A)
i1=0
i2=N-1
cnt=1
l=1
r=N-2
ans=A[i2]-A[i1]
while cnt<N-1:
    cnt+=1
    j1=max((abs(A[i1]-A[l]),l),(abs(A[i1]-A[r]),r))
    j2=max((abs(A[i2]-A[l]),l),(abs(A[i2]-A[r]),r))
    (j,lr),d=max((j1,1),(j2,2))
    ans+=j
    if d==1:
        i1=lr
    else:
        i2=lr
    if lr==l:
        l+=1
    else:
        r-=1
print(ans)