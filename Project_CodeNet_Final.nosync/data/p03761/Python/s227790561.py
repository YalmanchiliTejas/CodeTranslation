n = int(input())

A = [chr(i) for i in range(ord('a'), ord('z') + 1)]

B = []

for i in range(n):
    B.append(input())

C = []
m = 100
for i in A:
    for j in B:
        n = j.count(i)
        if n < m:
            m = n
    C.append(m)
    m = 100
s = ""
for i, j in zip(A, C):
    s += i * j
print(s)