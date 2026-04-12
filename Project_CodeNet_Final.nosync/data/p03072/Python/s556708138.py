n=int(input())
h=list(map(int,input().split()))
cnt=1
for i in range(1,n):
    flg=True
    for j in range(i):
        if h[j]>h[i]:
            flg=False
    if flg==True:
        cnt+=1
print(cnt)