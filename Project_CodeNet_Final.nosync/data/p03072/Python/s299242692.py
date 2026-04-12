N=int(input().strip())
H=list(map(int,input().split()))

x=H[0]
cnt=1
for i in range(N-1):
    if H[i+1]>=x:
        cnt+=1
        x=H[i+1]
print(cnt)