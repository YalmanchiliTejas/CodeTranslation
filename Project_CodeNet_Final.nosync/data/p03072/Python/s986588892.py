N=int(input())
X=[int(i) for i in input().split()]
ans=1
for i in range(1,N):
    if X[i] >= max(X[0:i]): ans+=1
print(ans)