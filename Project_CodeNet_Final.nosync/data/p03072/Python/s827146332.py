N=int(input())
H=list(map(int,input().split()))
cnt=1
before=H[0]
for i in range(1,N):
    if before <= H[i]:
        cnt+=1
    before=max(before,H[i])
print(cnt)
            