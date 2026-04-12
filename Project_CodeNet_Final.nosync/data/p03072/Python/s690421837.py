n=int(input())
H=list(map(int,input().split()))
ans=0
hgt=0
for i in range(n):
    if H[i]>=hgt:
        ans+=1
    hgt=max(hgt,H[i])
print(ans)
