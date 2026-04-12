N = int(input())
H = list(map(int, input().split()))
max = H[0]
cnt = 1
for i in range(1, len(H)):
    if max <= H[i]:
        max = H[i]
        cnt += 1
print(cnt)