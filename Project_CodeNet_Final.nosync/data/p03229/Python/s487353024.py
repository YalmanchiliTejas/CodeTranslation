from collections import deque

N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()
array = deque([A[0]])
a_len = 1
count = 0
idx = 0
result1 = 0

while a_len < N:
    if count % 2 == 0:
        array.appendleft(A[-idx-1])
        array.append(A[-idx-2])
    else:
        array.appendleft(A[idx+1])
        array.append(A[idx+2])
        idx += 2
    count += 1
    a_len += 2

for i in range(N-1):
    result1 += abs(array[i] - array[i+1])

array = deque([A[-1]])
a_len = 1
count = 0
idx = 0
result2 = 0

while a_len < N:
    if count % 2 != 0:
        array.appendleft(A[-idx])
        array.append(A[-idx-1])
    else:
        array.appendleft(A[idx])
        array.append(A[idx+1])
        idx += 2
    count += 1
    a_len += 2

for i in range(N-1):
    result2 += abs(array[i] - array[i+1])

print(max(result1, result2))