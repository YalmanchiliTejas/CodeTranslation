H, W = map(int, input().split())
A = [input() for _ in range(H)]

while '.' * W in A:
    A.remove('.' * W)

remove_j = set()
for j in range(W):
    if set([A[i][j] for i in range(len(A))]) == {'.'}:
        remove_j.add(j)

active_j = set(range(W)) - remove_j
active_j = sorted(list(active_j))
for a in A:
    print(''.join([a[j] for j in active_j]))
