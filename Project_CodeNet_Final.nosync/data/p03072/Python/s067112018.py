n=int(input())
H=list(map(int,input().split()))
ans=0
for i in range(n):
    A=H[:i+1]
    if max(A)==A[-1]:
        ans+=1
print(ans)