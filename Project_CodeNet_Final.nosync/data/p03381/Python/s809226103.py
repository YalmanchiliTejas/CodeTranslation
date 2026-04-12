
n = int(input())
x = list(map(int, input().split()))
x_sort = x.copy()
x_sort.sort()
row = x_sort[n//2 - 1]
high = x_sort[n//2]

for i in range(n):
    if x[i] <= row:
        print(high)
    else:
        print(row)
