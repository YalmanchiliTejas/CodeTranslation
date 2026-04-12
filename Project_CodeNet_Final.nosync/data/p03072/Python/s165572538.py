N=int(input())
H=list(map(int,input().split()))

P=H[0]
cnt=1
for i in range(1,N):
    if H[i]>=P:
        cnt+=1
        P=H[i]
print(cnt)