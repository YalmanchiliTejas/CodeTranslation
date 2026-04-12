H, W = map(int, input().split())
A = [0] * H
for _ in range(H):
    A[_] = input()
l = []
l2 = []
count = 0

for i in range(W):
    for j in range(H):
        if A[j][i] == '.':
            count += 1
    if count == H:
        l.append(i)
    count = 0
l.sort(reverse = True)
for k in range(H):
    for m in l:
        A[k] = A[k][:m] + A[k][m + 1:]
# print(A)
# for l in range(H):
#     if A[l] == '.' * len(A[l]):
#         l2.append(l)
# for _ in l2:
#     A.pop(_)
B = [i for i in A if i != '.'*len(A[0])]
# print(B)
for _ in range(len(B)):
    print(B[_])