n=int(input())
h=list(map(int,input().split()))
maxh=h[0]
cnt=1
for i in range(1,n):
    if max(maxh,h[i])==h[i]:
        cnt+=1
        maxh=h[i]
print(cnt)