N, X, M = map(int, input().split())

used = [0] * M
a = []

A = X
for i in range(N):
    if used[A] != 0:
        break
    used[A] = 1
    a.append(A)
    A = A * A % M

for i in range(len(a)):
    if a[i] == A:
        break
j = i

if a[-1] != 0:
    result = sum(a[:j])
    a = a[j:]
    l = len(a)
    x = (N - j) // l
    y = (N - j) - x * l
    s = sum(a)
    result += s * x
    result += sum(a[:y])
    print(result)
else:
    s = sum(a)
    print(s)
