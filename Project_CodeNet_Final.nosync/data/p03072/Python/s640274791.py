n = int(input())
lst = [int(x) for x in input().split()]

r = 1
for i in range(1, n):
    for j in range(0, i):
        if lst[i] >= lst[j]:
            pass
        else:
            break
        if i == j + 1:
            r += 1

print(r)