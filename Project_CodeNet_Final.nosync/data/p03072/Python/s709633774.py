N=int(input())
H=list(map(int,input().split()))
Hlist=[]
cnt=0
for i in range(N):
    Hlist.append(H[i])
    if max(Hlist)==H[i]:
        cnt+=1
print(cnt)