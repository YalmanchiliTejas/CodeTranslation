n = int(input())
h = [int(i) for i in input().split()]

maxh = h[0]
count = 1

for i in range(1, len(h)):
    if h[i] < maxh:
        pass
    else:
        count += 1
        maxh = h[i]
print(count)
