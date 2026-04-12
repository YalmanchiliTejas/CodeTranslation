n=int(input())
a=list(map(int,input().split()))
max=a[0]
res=0
for i in range(n):
    if a[i]>=max:
        res+=1
        max=a[i]
print(res)