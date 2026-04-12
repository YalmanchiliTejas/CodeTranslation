n=int(input())
h=list(map(int,input().split()))
hst=h[0]
cnt=1
for i in range(1,n):
    if h[i]>=hst:
        hst=h[i]
        cnt+=1
print(cnt)
