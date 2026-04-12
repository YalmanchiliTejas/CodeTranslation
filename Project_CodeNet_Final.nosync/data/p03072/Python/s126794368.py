N = int(input())
h = list(map(int, input().split()))

tmp_max = 0
count = 0
for i in range(N):
    if h[i] >= tmp_max:
        tmp_max = h[i]
        count += 1
    else:
        pass
print(count)