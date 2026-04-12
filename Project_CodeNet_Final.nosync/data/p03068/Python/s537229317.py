N = int(input())
S = list(input())
K = int(input())

Sk = S[K-1]

for i in range(N):
    if S[i]!=Sk:
        S[i]="*"

output = ""

for j in S:
    output = output + j

print(output)