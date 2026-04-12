n=int(input())
h=list(map(int,input().split()))
res=1
for i in range(1,n):
    if max(h[:i])<=h[i]:
        res+=1
print(res)