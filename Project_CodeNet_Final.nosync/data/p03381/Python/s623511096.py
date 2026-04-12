n = int(input())
x = list(map(int, input().split()))
x_sort = sorted(x)
first_median = x_sort[n//2 - 1]
second_median = x_sort[n//2]
for i in x:
    if i <= first_median:
        print(second_median)
    else:
        print(first_median)