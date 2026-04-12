n = int(input())
a = []
for i in range(n):
    ai = int(input())
    a.append(ai)

lst = [a[0]]
for i in range(1, n):
    ai = a[i]
    left = -1
    right = len(lst)
    while left+1 < right:
        mid = (left + right) // 2
        if lst[mid] < ai:
            right = mid
        else:
            left = mid
    if right == len(lst):
        lst.append(ai)
    else:
        lst[right] = ai
print(len(lst))