
N= int(input())
a=[0]*N
ans=0
b=list(map(int,input().split()))

for i in range(N):
    if max(a)<=b[i] and 0<=b[i]:
        ans +=1
        a[i]=b[i]
    else:
        a[i]=b[i]
print(ans)