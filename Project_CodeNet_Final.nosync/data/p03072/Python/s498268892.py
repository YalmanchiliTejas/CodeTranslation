N=int(input())
H=list(map(int,input().split()))
M=H[0]
ans=1
for i in range(N-1):
    if H[i+1] >= M :
        M=H[i+1]
        ans+=1
    else:
        pass
print(ans)