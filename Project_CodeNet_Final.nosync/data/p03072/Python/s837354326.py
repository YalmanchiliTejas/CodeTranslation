from functools import reduce

n = int(input())
h = list(map(int, input().split()))
# tuple型の一番目を参照
h_max = 0
count = 0

for i in range(n):
    if h_max <= h[i]:
        h_max = h[i]
        count += 1

print(count)
