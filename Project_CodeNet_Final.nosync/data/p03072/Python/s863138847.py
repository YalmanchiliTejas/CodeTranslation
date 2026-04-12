N = input()
hlt = input().split()

for i in range(0, len(hlt)):
    hlt[i] = int(hlt[i])

cnt = 1
for i in range(1, len(hlt)):
    for j in range(0, i):
        if hlt[j] > hlt[i]:
            break
    else:
        cnt += 1

print(cnt)