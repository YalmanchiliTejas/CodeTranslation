n = int(input())
array = [int(x) for x in input().split()]

cnt = 1
tmp = array[0]
for x in range(1, n):
    if array[x] >= tmp:
        tmp = array[x]
        cnt += 1
else:
    print(cnt)