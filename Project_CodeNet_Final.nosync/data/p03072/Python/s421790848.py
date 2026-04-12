n = int(input())
a = list(map(int, input().split()))
counter = 0
for i in range(n):
    counter += 1
    for j in range(i):
        if a[i] < a[j]:
            counter -= 1
            break
print(counter)
