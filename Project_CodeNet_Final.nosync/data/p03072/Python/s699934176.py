N = int(input())
H = list(map(int, input().split()))
count = 0
highest = 0
for height in H:
    if highest <= height:
        count += 1
        highest = height
print(count)