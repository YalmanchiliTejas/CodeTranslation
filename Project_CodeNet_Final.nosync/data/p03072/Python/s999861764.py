n = int(input())
listH=list(map(int, input().split()))
index=0
count=0
max=0
while index < n:
    if listH[index] >= max:
        count+=1
        max = listH[index]
    index+=1
print(count)