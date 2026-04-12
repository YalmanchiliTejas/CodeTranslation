N = int(input())
ls = list(map(int, input().split()))
m = 1000000007
sumNum = sum(ls)
currentSum, lastAns = 0, 0
for i in range(N -1):
    currentSum += ls[i]
    lastAns = (lastAns + (ls[i] * (sumNum - currentSum))) % m
print(lastAns)