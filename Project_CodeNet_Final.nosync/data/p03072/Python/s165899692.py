n=int(input())
h=list(map(int,input().split()))
cnt=1
for i in range(1,n):
    canSee=True
    for j in range(i):
        if h[j]>h[i]:
            canSee=False
    if canSee:
        cnt+=1
print(cnt)
