n = int(input())
h = list(map(int, input().split()))

count = 0
max_val = 0
for x in h:
    if max_val <= x:
        count += 1
        max_val = x
print(count)
