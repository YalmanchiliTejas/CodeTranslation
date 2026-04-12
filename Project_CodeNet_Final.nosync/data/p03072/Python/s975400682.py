N=int(input())
H=list(map(int,input().split()))
cnt=1
for j in range(1,N):
    if max(H[0:j+1])==H[j]:
        cnt+=1
print(cnt)