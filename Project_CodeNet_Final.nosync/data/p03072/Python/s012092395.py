n = int(input())
list1 = [int(k) for k in input().split()]
count = 1
for i, item in enumerate(list1):
    for j in range(0, i):
        if list1[j] > item:
            break
        if i - j == 1:
            count += 1
print(count)