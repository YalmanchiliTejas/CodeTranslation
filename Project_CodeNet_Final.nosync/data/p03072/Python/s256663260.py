N = int(input())
H = list(map(int, input().split()))

count = 0
max = H[0]

for h in H:
    if max <= h:
        max = h
        count += 1

print(count)