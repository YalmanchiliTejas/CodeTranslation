H, W = list(map(int, input().split()))
A = [list(input()) for _ in range(H)]
delh, delw = [], []
for i in range(H):
    if all([True if i == '.' else False for i in A[i]]):
        delh.append(i)
B = [list(x) for x in zip(*A)]
for i in range(W):
    if all([True if i == '.' else False for i in B[i]]):
        delw.append(i)
B = [b for i, b in enumerate(B) if i not in delw]
A = [list(x) for x in zip(*B)]
A = [a for i, a in enumerate(A) if i not in delh]
[print(''.join(a)) for a in A]