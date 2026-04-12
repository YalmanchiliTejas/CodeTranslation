_ = input()
max_h = 0
count = 0
high = map(int, input().split())
for height in high:
    if max_h <= height:
        max_h = height
        count += 1
print(count)