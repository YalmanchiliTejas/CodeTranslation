n = int(input())
h = list(map(int, input().split()))

cnt = 0
for i in range(len(h)):
    if i == 0:
        cnt += 1
    else:
        for j in range(i):
            if h[i] < h[j]:
                break
        else:
            cnt += 1

print(cnt)
