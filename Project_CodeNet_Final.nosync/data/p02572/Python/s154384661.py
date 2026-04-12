n=int(input())
l=list(map(int,input().split()))
sum=sum(l)
s=0
for i in range(n):
    s+=l[i]*(sum-l[i])
print(s//2%(10**9+7))