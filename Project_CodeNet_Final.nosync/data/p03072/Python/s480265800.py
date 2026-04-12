n = int(input())
h_list = [int(x) for x in input().split()]

ans = 0
h_max = 0
for h in h_list:
    if h < h_max:
        continue
    ans += 1
    h_max = h
print(ans)