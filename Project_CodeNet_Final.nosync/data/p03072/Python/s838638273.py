n = int(input())
H = list(map(int, input().split()))

cnt = 1

temp = H[0]

for i in range(1, n):
    if temp <= H[i]:
        temp = H[i]
        cnt += 1

print(cnt)
