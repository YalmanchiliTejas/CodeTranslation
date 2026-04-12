n=int(input())
H=list(map(int,input().split()))
cnt=0; m=0
for i in range(0,n):
    if H[i]>=m:
        m=max(H[i],m)
        cnt+=1
print(cnt)