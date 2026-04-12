n = int(input())
h_list = list(map(int, input().split()))

h_max = 0
cnt = 0
for h in h_list:
    if h >= h_max:
        h_max = h
        cnt += 1

print(cnt)