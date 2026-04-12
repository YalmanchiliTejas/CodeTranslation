N, X, M = map(int, input().split())

"""
id[X] Xを何番目に訪問したか。-1で無ければ訪問済み。
Xをメモ  A[i+1] = (A[i] * A[i]) % M
length = ループが終わるまでの長さ
"""

id = [-1] * M
A = []  # 訪問したものをメモ
length = 0
total = 0
while id[X] == -1:
    A.append(X)
    id[X] = length
    length += 1
    total += X
    X = (X * X) % M
syuki = length - id[X]
syukisum = sum(A[id[X] : length])
# for i in range(id[X], length):
#     syukisum += A[i]

ans = 0
if N <= length:
    ans = sum(A[:N])
else:
    ans += total
    N -= length
    loop, res = divmod(N, syuki)
    ans += syukisum * loop
    ans += sum(A[id[X] : id[X] + res])
print(ans)
