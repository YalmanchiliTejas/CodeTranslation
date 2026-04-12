N=int(input())
H=list(map(int,input().split()))
mx=H[0]
cnt=1
for i in range(1,N):
    if mx<=H[i]:
        cnt+=1
    mx=max(mx,H[i])
print(cnt)