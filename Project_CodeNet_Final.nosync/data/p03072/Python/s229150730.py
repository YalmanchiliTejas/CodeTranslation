n = int(input())
height_list = [int(i) for i in input().split(" ")]
c = 0

for i, height in enumerate(height_list):
    if i == 0:
        c += 1
    else:
        if height >= max(height_list[:i]):
            c += 1
print(c)
