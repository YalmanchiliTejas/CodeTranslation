N = int(input())
S = input()
K = int(input())

check = S[K-1]

A = []

for i in range(N):
    if check != S[i]:
        A.append("*")
    else:
        A.append(check)
print("".join(A))

