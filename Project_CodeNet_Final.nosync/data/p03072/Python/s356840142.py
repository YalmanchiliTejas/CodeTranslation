N=int(input())
H = list(map(int,input().split()))
ans=0
for i in range(N):
    if max(H[0:i+1])<=H[i]:
        ans+=1
print(ans)
