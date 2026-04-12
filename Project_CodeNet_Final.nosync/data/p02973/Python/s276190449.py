import bisect, collections

n = int(input())
num = collections.deque([])
for i in range(n):
    a = int(input())
    temp = bisect.bisect_left(num, a)
    if temp == 0:
        num.appendleft(a)
    else:
        num[temp - 1] = a
print(len(num))