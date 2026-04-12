import copy
N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
B = copy.deepcopy(A)
sum1 = 0
sum2 = 0
center = -(-N // 2) - 1
if N%2 == 1:
    for i in range(N):
        if i == 0:
            beforeNum = A.pop(center)
        else:
            if i%2 == 1:
                num = A.pop(-1)
            else:
                num = A.pop(0)
            sum1 += abs(beforeNum - num)
            beforeNum = num
    for i in range(N):
        if i == 0:
            beforeNum = B.pop(center)
        else:
            if i%2 == 1:
                num = B.pop(0)
            else:
                num = B.pop(-1)
            sum2 += abs(beforeNum - num)
            beforeNum = num
else:
    for i in range(N):
        if i == 0:
            beforeNum = A.pop(center)
        else:
            if i%2 == 1:
                num = A.pop(-1)
            else:
                num = A.pop(0)
            sum1 += abs(beforeNum - num)
            beforeNum = num
    center = center + 1
    for i in range(N):
        if i == 0:
            beforeNum = B.pop(center)
        else:
            if i%2 == 1:
                num = B.pop(0)
            else:
                num = B.pop(-1)
            sum2 += abs(beforeNum - num)
            beforeNum = num
print(max(sum1,sum2))
