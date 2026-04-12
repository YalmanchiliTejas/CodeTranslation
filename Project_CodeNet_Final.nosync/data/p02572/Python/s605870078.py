n=int(input())
a=list(map(int,input().split()))

sum=0
f=0

for i in range(n-1):
    f=f+a[i]
    sum+=f*a[i+1]

print(sum%(10**9+7))