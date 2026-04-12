from sys import stdin

N = int(stdin.readline().rstrip())
H_list = [int(x) for x in stdin.readline().rstrip().split()]

if N == 1:
    print(1)
    exit()

cnt = 1
if H_list[1] >= H_list[0]:
    cnt += 1

for i in range(2, N):
    if H_list[i] >= max(H_list[:i]):
        cnt += 1

print(cnt)
