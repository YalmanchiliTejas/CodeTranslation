n = int(input())
h_array = [int(x) for x in input().split()]
cnt = 0
highest = h_array[0]
for index, h in enumerate(h_array, 1):
    if highest <= h:
        cnt += 1
        highest = h
print(cnt)
