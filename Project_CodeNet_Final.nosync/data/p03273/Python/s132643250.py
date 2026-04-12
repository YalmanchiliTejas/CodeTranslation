H, W = map(int, input().split())
A = []
check = [0] * W

for i in range(H):
    row = input()
    if '#' not in row:
        continue
    else:
        for j in range(W):
            if row[j] == '#':
                check[j] += 1
        A.append(row)

for idx in range(len(A)):
    l_ = [a for i, a in enumerate(list(A[idx])) if check[i] != 0]
    A[idx] = ''.join(l_)

for l in A:
    print(l)