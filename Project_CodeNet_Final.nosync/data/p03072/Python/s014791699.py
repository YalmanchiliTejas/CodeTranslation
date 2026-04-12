N = int(input())
hList = [int(x) for x in input().split()]

count = 0
for i,h in enumerate(hList):
    ng = False
    for j in range(i+1):
        if hList[j] > h:
            ng = True
            break
    if ng == False:
        count += 1
print(count)