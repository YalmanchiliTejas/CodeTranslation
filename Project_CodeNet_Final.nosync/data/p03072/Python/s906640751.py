n = int(input())
listA = list(map(int, input().split()))
a=1
for i in range(1,n):
    if listA[i-1]>listA[i]:
        listA[i]=listA[i-1]
    else:
        a=a+1
print(a)