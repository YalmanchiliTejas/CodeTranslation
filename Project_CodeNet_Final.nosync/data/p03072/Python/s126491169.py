N = int(input())
H_list = [int(i) for i in input().split()]
res = 1

for i in range(1, N):
    if H_list[i] >= max(H_list[:i]):
        res += 1

print(res)