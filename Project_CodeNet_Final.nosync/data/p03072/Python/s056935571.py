n = int(input())
h = list(map(int, input().split()))
count = 0

for i in range(len(h)):
    for j in range(i + 1):
        if h[i] < h[j]:
            break
        if j == i:
            count += 1

print(count)
