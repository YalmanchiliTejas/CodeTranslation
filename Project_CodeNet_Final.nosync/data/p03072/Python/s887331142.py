N = int(input())
height_list = list(map(int,input().split()))

max_height = 0
counter = 0

for n in range(N):
    if max_height <= height_list[n]:
        counter += 1
        max_height = height_list[n]
        continue
print(counter)