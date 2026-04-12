N = int(input())
A = [int(input()) for i in range(N)]

A.sort()

if len(A) % 2 == 1:
    order1 = [-1, -1]
    for i in range(len(A)-2):
        if i % 2 == 0:
            order1.append(2)
        else:
            order1.append(-2)

    order2 = [1, 1]
    for i in range(len(A)-2):
        if i % 2 == 0:
            order2.append(-2)
        else:
            order2.append(2)
else:
    order1 = [-1, 1]
    for i in range(len(A) - 2):
        if i % 2 == 0:
            order1.append(2)
        else:
            order1.append(-2)

    order2 = [-1, 1]
    for i in range(len(A) - 2):
        if i % 2 == 0:
            order2.append(-2)
        else:
            order2.append(2)


order1.sort()
order2.sort()

sum1 = 0
sum2 = 0
for x, y, z in zip(A, order1, order2):
    sum1 += x * y
    sum2 += x * z

print(max(sum1, sum2))