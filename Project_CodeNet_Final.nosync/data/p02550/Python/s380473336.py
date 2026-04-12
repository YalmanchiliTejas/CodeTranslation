N, X, M = map(int, input().split())

I = [-1] * M
A = []
total = 0
while (I[X] == -1):
    A.append(X)
    I[X] = len(A)
    total += X
    X = (X * X) % M

# print(f'{A=}')
# print(f'{I[:20]=}')
# print(f'{total=}')
# print(f'{X=}, {I[X]=}')

c = len(A) - I[X] + 1
s = sum(A[I[X] - 1:])
# print(f'{c=}, {s=}')
ans = 0
if N < len(A):
    ans += sum(A[:N])
else:
    ans += total
    N -= len(A)
    ans += s * (N // c)
    N %= c
    ans += sum(A[I[X] - 1:I[X] - 1 + N])
print(ans)
