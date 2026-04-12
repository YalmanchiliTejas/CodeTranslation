N = int(input())
H = list(map(int, input().split()))
count, max_h = 0, 0
for h in H:
    if h >= max_h:
        count += 1
        max_h = h
print(count)