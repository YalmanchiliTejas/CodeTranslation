n=int(input())
h=list(map(int,input().split()))
max=h[0]
cnt=1
for i in range(1,n):
    if h[i]>=max:
        cnt+=1
        max=h[i]
print(cnt)