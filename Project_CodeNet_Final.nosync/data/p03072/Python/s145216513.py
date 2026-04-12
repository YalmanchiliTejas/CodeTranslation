N = int(input())
HList = [int(i) for i in input().split(" ")]
stn = -1
count = 0

for i in range(len(HList)) :
    if HList[i] >= stn  :
        count += 1
    if stn < HList[i] :
        stn = HList[i]

print(count)