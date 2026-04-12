N = int(input())
H_list = list(map(int, input().split()))

res = 0
cum_max = 0
for i in range(N):
    cum_max = max(cum_max, H_list[i])
    if cum_max <= H_list[i]:
        res += 1
print(res)