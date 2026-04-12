N = int(input())
H = list(map(int, input().split()))

count = 1
for idx, h in enumerate(H):
    if idx == 0:
        continue
    else:
        if max(H[:idx]) <= h:
            count += 1
print(count)