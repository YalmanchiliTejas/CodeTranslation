n = int(input())
lh = list(map(int, input().split()))
th = 0
count = 0

for i in range(n):
    if lh[i] >= th:
        th = lh[i]
        count += 1

print(count)
