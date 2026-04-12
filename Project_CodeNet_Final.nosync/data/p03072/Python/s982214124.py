n = int(input())
H = list(map(int, input().split()))
cnt = 1
for i in range(1, n):
    max_num = max(H[:i])
    if H[i] >= max_num:
        cnt += 1

print(cnt)