n=int(input())
H=list(map(int,input().split()))
cnt=1
for i in range(1,n):
    res=0
    for j in range(i):
        if H[i]>=H[j]:
            res+=1
        if res==i:
            cnt+=1
print(cnt)