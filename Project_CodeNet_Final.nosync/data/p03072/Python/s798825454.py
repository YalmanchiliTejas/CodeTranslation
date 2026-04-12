N=int(input())
H=[int(i) for i in input().split()]
ans=1
for i in range(1,N):
    flag=1
    for j in range(i):
        if H[j]>H[i]:
            flag=0
            break
    if flag==1:
        ans+=1
print(ans)
