N = int(input())
H = [int(h) for h in input().split()]


cnt = 0
for i in range(N):
    isSucces = True
    for j in range(i):
        if H[j] > H[i]:
            isSucces = False
            break
    if isSucces:
        cnt += 1

print(cnt)

