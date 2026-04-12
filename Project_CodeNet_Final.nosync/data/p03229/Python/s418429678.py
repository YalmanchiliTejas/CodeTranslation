n = int(input())
a = []
for i in range(n):
    ai = int(input())
    a.append(ai)

a = sorted(a)

sum_1 = 0
sum_2 = 0
if len(a) % 2 == 1:
    for i in range(0, len(a)//2):
        sum_1 += a[-i-1] - a[i]
        sum_2 += a[-i-1] - a[i]
    for i in range(1, len(a)//2):
        sum_1 += a[-i] - a[i]
    for i in range(0, len(a)//2-1):
        sum_2 += a[-i-2] - a[i]
    sum_1 += a[len(a)//2]-a[0]
    sum_2 += a[-1]-a[len(a)//2]
    print(max(sum_1, sum_2))

else:
    for i in range(0, len(a)//2-1):
        sum_1 += a[-i-1] - a[i]
        sum_2 += a[-i-1] - a[i]
    for i in range(1, len(a)//2):
        sum_1 += a[-i] - a[i]
    for i in range(0, len(a)//2-1):
        sum_2 += a[-i-2] - a[i]
    sum_1 += a[-len(a)//2] - a[0]
    sum_2 += a[-1] - a[len(a)//2-1]
    print(max(sum_1, sum_2))
