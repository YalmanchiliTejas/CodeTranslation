N = int(input())
h_ls = [int(i) for i in input().split()]
_max = 0
cnt = 0
for h in h_ls:
    if _max <= h:
        cnt += 1
        _max = h
print(cnt)