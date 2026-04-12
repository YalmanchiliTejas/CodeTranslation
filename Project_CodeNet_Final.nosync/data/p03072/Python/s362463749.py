N=int(input())
Hl=list(map(int,input().split()))
cnt=0
for i in range(1,N+1):
    if all(Hl[i-1]>=h for h in Hl[:i]):
        cnt+=1
print(cnt)