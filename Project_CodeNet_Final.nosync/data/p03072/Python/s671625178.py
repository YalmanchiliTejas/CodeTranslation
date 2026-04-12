N = int(input())
H = list(map(int, input().split()))

max_h = 0
count = 0
for i, h_i in enumerate(H):
    if max_h <= h_i:
        max_h = h_i
        count += 1

print(count)