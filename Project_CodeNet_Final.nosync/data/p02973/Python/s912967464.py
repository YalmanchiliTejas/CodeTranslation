def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
from bisect import bisect_right

n = getN()
mx = []
k = 0
for i in range(n):
    num = -(getN())
    ins = bisect_right(mx, num)
    if ins == k:
        mx.append(num)
        k += 1
    else:
        mx[ins] = num
    # print(ins, mx)

print(len(mx))