N=int(input())
H=list(map(int,input().split()))
max_H=H[0]
ans=1
for i in range(1,N):
    if H[i]>=max_H:
        ans+=1
        max_H=H[i]
print(ans)