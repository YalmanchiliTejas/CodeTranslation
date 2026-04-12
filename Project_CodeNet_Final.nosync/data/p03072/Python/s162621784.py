N=int(input())
H=list(map(int,input().split()))
ans=0
for i in range(len(H)):
    if i==0:
        ans+=1
    elif max(H[0:i])<=H[i]:
        ans+=1
print(ans)