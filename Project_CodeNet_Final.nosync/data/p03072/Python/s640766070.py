N = int(input())
H = [int(a) for a in input().split()]

count = 1
for i, h in enumerate(H[1:], 1):
    if sum([1 for j in range(i) if h >= H[j]]) == i:
        count += 1

print(count)
