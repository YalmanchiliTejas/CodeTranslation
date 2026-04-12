N = input()
list = list(map(int, input().split()))

cnt = 1

for i, row1 in zip(range(len(list)), list[1:]):
    for row2 in list[:i+1]:
        if row2 > row1:
            break
    else:
        cnt += 1

print(cnt)

