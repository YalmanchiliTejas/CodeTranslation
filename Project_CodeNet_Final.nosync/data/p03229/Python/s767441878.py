import collections

N = int(input())

A = [0] * N
for i in range(N):
    A[i] = int(input())


A = sorted(A)

if N % 2 == 1:
    d1 = A[0:N // 2 + 1]
    u1 = A[N // 2 + 1:N + 1]
else:
    d1 = A[0:N // 2]
    u1 = A[N // 2:N + 1]

d1 = collections.deque(d1)
u1 = collections.deque(u1)
d1.rotate(1)
u1.rotate(-1)

sum1 = 0
i = 0
while (True):
    # print("{},{},{}".format(i, len(d1), len(u1)))
    if i >= len(d1) or i >= len(u1):
        break
    sum1 += abs(u1[i] - d1[i])

    if i+1 >= len(d1) or i >= len(u1):
        break
    sum1 += abs(u1[i] - d1[i + 1])
    i += 1

sum2 = 0
i = 0
while (True):
    # print("{},{},{}".format(i, len(d1), len(u1)))
    if i >= len(d1) or i >= len(u1):
        break
    sum2 += abs(u1[i] - d1[i])

    if i >= len(d1) or i+1 >= len(u1):
        break
    sum2 += abs(u1[i+1] - d1[i])
    i += 1

###########################

if N % 2 == 1:
    d1 = A[0:N // 2]
    u1 = A[N // 2:N + 1]

d1 = collections.deque(d1)
u1 = collections.deque(u1)
d1.rotate(1)
u1.rotate(-1)

sum3 = 0
i = 0
while (True):
    # print("{},{},{}".format(i, len(d1), len(u1)))
    if i >= len(d1) or i >= len(u1):
        break
    sum3 += abs(u1[i] - d1[i])

    if i+1 >= len(d1) or i >= len(u1):
        break
    sum3 += abs(u1[i] - d1[i + 1])
    i += 1

sum4 = 0
i = 0
while (True):
    # print("{},{},{}".format(i, len(d1), len(u1)))
    if i >= len(d1) or i >= len(u1):
        break
    sum4 += abs(u1[i] - d1[i])

    if i >= len(d1) or i+1 >= len(u1):
        break
    sum4 += abs(u1[i+1] - d1[i])
    i += 1


print(max(sum1, sum2, sum3, sum4))
