n = int(input())
h_list = list(map(int, input().split()))
h_max = h_list[0]
cnt = 1
for i in range(1, n):
    if h_list[i] >= h_max:
        h_max = h_list[i]
        cnt += 1
print(cnt)        