n = int(input())
hh = list(map(int, input().split()))
hh.insert(0, 0)

cnt = 0
for i in range(1, len(hh)):
    for j in range(0, i):
        if hh[i] < hh[j]:
            break
    else:
        cnt += 1

print(cnt)
