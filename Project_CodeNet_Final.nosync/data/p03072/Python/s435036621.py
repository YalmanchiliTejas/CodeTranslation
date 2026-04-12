n = int(input().split()[0])
h_list = list(map(int, input().split()))
c = 1

for i, h in enumerate(h_list[1:]):
    pre_max = max(h_list[:i+1])
    if pre_max <= h:
        c += 1

print(c)