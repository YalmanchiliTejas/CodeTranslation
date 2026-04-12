n = int(input())

li_h = list(map(int, input().split()))

max_height = li_h[0]
counter = 1

for i in range(1, n):
    if max_height <= li_h[i]:
        counter += 1
    max_height = max(max_height, li_h[i])

print(counter)
