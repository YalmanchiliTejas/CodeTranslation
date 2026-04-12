n= int(input())
li = list(map(int,input().split()))
k = 1
for i in range(1,n):
    f=0
    for j in range(i):
        if li[j]>li[i]:
            f=1
    if f==0:
        k+=1
print(k)