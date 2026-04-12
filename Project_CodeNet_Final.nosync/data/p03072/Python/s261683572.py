N = int(input())
HList = list(map(int,input().split()))
count = 1
max1 = HList[0]
for i in range(1,N):
    if max1 <= HList[i]:
        count += 1
    if max1 < HList[i]:
        max1 = HList[i]
print(count)
