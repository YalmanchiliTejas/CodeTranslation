N=int(input())
H=[int(i) for i in input().split()]
ans=1
max_high=H[0]
for i in range(1,N):
    if H[i]>=max_high:
        ans+=1
        max_high=H[i]
print(ans)