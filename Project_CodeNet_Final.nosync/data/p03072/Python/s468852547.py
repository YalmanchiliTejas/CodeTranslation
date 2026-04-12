N = int(input())
H = list(map(int, input().split()))

tmp_max = 0
update_cnt = 0
for i in range(0, N):
    if tmp_max <= H[i]:
        tmp_max = H[i]
        update_cnt += 1

print(update_cnt)
