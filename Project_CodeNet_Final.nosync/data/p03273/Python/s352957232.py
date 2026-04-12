import numpy as np

def a(mat):
    new = []
    tmp_mat = mat.T
    for row in tmp_mat:
        if len(set(row)) == 1 and row[0] == '.':
            continue
        new.append(row)
    new = np.array(new)
    return new.T.tolist()





h, w = list(map(int, input().split()))

# matrix
results = []



for _ in range(h):
    row = list(input())
    if ''.join(row) == '.'*w:
        continue
    results.append(row)

results = np.array(results)

for row in a(results):
    print(''.join(row))

