n = int(input())
x = [int(a) for a in input().split()]
sorted_x = sorted(x)
for elem in x:
    if elem >= sorted_x[(len(x) + 1) // 2]:
        print(sorted_x[(len(x) + 1) // 2 - 1])
    else:
        print(sorted_x[(len(x) + 1) // 2])
    