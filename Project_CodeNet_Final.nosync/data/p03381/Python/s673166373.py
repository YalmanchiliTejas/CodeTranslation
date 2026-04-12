n = int(input())
x = list(map(int, input().split()))

x1 = sorted(x)
tmp1 = n // 2
tmp2 = (n // 2) - 1
val1 = x1[tmp1]
val2 = x1[tmp2]

for i in range(len(x)):
    if x[i] < val1:
        print(val1)
    else:
        print(val2)
