n = int(input())
x = list(map(int, input().split()))

lst = sorted(x)
small_med = lst[n // 2 - 1]
big_med = lst[n // 2]

for num in x:
    if num > small_med:
        print(small_med)
    else:
        print(big_med)