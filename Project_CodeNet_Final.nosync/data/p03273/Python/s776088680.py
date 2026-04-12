H, W = map(int, input().split())
A = []
for i in range(H):
    l = input()
    if any([c == '#' for c in l]):
        A.append(l)

for j in range(W):
    if all([a[j] == '.' for a in A]):
        for i in range(len(A)):
            A[i] = A[i][:j] + '*' + A[i][j + 1:]
for a in A:
    print(a.replace('*', ''))