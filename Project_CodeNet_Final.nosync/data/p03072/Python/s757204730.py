n=int(input())
H=[int(i) for i in input().split()]

lim=0
ans=0
for i in range(n):
    if H[i]>=lim:
         ans+=1
         lim=H[i]
print(ans)