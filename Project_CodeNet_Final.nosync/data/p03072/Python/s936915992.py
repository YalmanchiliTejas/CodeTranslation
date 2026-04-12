n=int(input())
l=[int(i) for i in input().split()]
x=1
for i in range(1,n):
    a=0
    for j in range(i):
        if l[i]>=l[j]:
            a+=1
    if a==i:
        x+=1
print(x)