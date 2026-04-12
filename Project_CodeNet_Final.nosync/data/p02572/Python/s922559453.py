n = int(input())
array = [int(x) for x in input().split(' ')]
s = 0
sums = []
for i in range(n-1, -1, -1):
    if i == n-1:
        sums.append(array[i])
    else:
        sums.append(sums[-1] + array[i])

sums.pop()
for i in range(n-1):
    s += array[i] * sums.pop()

print(s % (10 ** 9 + 7))