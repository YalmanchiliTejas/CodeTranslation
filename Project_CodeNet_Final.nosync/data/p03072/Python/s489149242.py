n = int(input())
H = list(map(int, input().split()))
count = 0
max = 1
for i in H:
    if i >= max:
        max = i
        count += 1
print(count)
