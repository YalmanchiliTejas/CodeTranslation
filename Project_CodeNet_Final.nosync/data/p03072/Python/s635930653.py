n = int(input())
h = list(map(int, input().split()))

max = h[0]
count = 0
for i in h:
    if max <= i:
        count += 1
        max = i
    else:
        continue
print(count)