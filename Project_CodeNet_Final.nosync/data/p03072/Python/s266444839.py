N = int(input())
H = list(map(int, input().split()))

count = 1
max_h = H[0]

for h in H[1:]:
    if h >= max_h:
        max_h = h
        count += 1
print(count)

