N = int(input())
H = list(map(int, input().split()))

res = 0
for i in range(len(H)):
    cnt = 0
    for j in range(0, i):
        if H[j] > H[i]:
            cnt += 1
    if cnt == 0:
        res += 1

print(res)
