N, M = map(int, input().split())
A = [None for i in range(M)]
B = [None for i in range(M)]
for i in range(M):
    A[i], B[i] = map(int, input().split())

s = []
past = [1]
for i, a in enumerate(A):
    if a == past[-1] and not B[i] in past:
        s.append(past+[B[i]])
for i, b in enumerate(B):
    if b == past[-1] and not A[i] in past:
        s.append(past+[A[i]])
num_paths = 0
while s:
    past = s.pop()
    if len(past) == N:
        num_paths += 1
        continue
    for i, a in enumerate(A):
        if a == past[-1] and not B[i] in past:
            s.append(past+[B[i]])
    for i, b in enumerate(B):
        if b == past[-1] and not A[i] in past:
            s.append(past+[A[i]])

print(num_paths)