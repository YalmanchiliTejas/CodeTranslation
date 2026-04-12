# solution
import io

n, m = map(int, input().split())
array = []

for i in range(n-1, -1, -1):
    qwe = list(input())
    if qwe!=["."]*m:
        array.append(qwe)

for j in range(m-1, -1, -1):
    cnt = 0
    for k in range(len(array)):
        if array[k][j]==".":
            cnt += 1
    if cnt ==len(array):
        for k in range(len(array)):
            array[k].pop(j)

for i in range(len(array)):
    print("".join(array[i]))