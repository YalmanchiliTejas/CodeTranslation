n = int(input())
li = list(map(int, input().split()))

count = 0
max_high = 0
for i in li:
    if max_high <= i:
        count += 1
        max_high = i

print(count) 