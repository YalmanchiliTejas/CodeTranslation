n=int(input())
h=list(map(int,input().split()))
cnt=1
for i in range(1,n):
    ok=True
    for j in range(i):
        if h[i]<h[j]:
            ok=False
    if ok:
        cnt+=1
print(cnt)