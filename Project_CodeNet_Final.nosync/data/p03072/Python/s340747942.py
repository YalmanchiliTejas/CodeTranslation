n=int(input())
h=list(map(int,input().split()))
MAX=h[0]
cnt=1
for i in range(1,n):
    if h[i]>=MAX:
        cnt+=1
        MAX=h[i]
print(cnt)