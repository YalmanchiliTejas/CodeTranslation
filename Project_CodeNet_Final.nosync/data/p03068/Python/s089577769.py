n = int(input())
S = list(input())
k = int(input())
s = S[k-1]

A = []
for i in range(n):
    a = S[i]
    if a != s:
        A.append("*")
    else:
        A.append(s)

print(*A, sep = "")