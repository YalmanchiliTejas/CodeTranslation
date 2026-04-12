N = list(map(int, input().split()))
A = list(map(int, input().split()))
max = -1
count = 0
for height in A:
    if max <= height:
        count += 1
        max = height
print(count)