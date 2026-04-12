n=int(input())
h=list(map(int,input().split()))
cnt=1
flg=True
for i in range(1,n):
    for j in range(i):
        if h[i]<h[j]:
            flg=False
    if flg:
        cnt+=1
    flg=True
print(cnt)