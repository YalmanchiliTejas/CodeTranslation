n = int(input())
a = list(map(int, input().split()))

m = a[0]
count = 1
for i in range(1, n):
    if a[i] > m:
        m = a[i]
        count += 1
    elif a[i] == m:
        count += 1

print(count)