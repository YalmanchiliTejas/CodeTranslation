N, X, M = map(int, input().split())

existence = [False] * M
a = []
A = X
for i in range(N):
    if existence[A]:
        break
    existence[A] = True
    a.append(A)
    A = A * A % M

for i in range(len(a)):
    if a[i] == A:
        loop_start = i
        break
else:
    loop_start = len(a)

result = sum(a[:loop_start])
N -= loop_start
if N != 0:
    a = a[loop_start:]
    loops = N // len(a)
    remainder = N % len(a)
    result += sum(a) * loops + sum(a[:remainder])
print(result)
