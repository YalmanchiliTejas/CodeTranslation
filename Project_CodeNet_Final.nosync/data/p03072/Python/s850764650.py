N=int(input())
a=list(input().split())
sum=1
most=0
for i in range(N-1):
    most=max(int(a[i]),most)
    if most<=int(a[i+1]):
        sum+=1
print(sum)
