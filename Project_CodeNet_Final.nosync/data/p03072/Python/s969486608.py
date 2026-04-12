N=int(input())
list=list(map(int,input().split()))
cnt=1
max=list[0]
for i in range(1,N):
    if(max <= list[i]):
        cnt+=1
        max=list[i]
print(cnt)
