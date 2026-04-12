N = int(input())
tmp_lst = input().split()
H_lst = []
for i in range(N):
    H_lst.append(int(tmp_lst[i]))

count = 1   #   一番西の必ず見えるところ
for i in range(1,N):
    ocean_vew = True
    for j in range(i):
        if H_lst[j] > H_lst[i]:
            ocean_vew = False
            break
    if ocean_vew:
        count += 1

print(count)