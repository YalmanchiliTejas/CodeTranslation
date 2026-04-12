line = input()
N = int(line)
line = input()
H = list(map(int, line.split()))

count = 1
for index, height in enumerate(H):
    tmp_count = 0
    if index == 0:
        continue
    for i in range(0,index):
        if H[i] > H[index]:
            continue
        tmp_count += 1
    if tmp_count == index:
        count += 1

print(count)
