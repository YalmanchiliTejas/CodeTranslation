c=int(input())
a=list(map(int,input().split()))
b=0
count=0
for i in range(0,c):
    if a[i]>=b:
        count=count+1
        b=a[i]
print(count)