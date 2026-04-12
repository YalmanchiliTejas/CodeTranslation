import math
import itertools
n, m = map(int, input().split())
e = [set(map(int, input().split())) for _ in range(m)]

n_list = []
for i in range(1, n+1):
    n_list.append(i)
n_array = sorted(list(itertools.permutations(n_list)))

count = 0

for i in range(math.factorial(n-1)):
    for j in range(n-1):
        if not (set(n_array[i][j:j + 2]) in e):
            break
    else:
        count += 1
print(count)