N = int(input())
S = input()
K = int(input())

s_k = S[K-1]

output = ""
for s in S:
    if s == s_k:
        output += s_k
    else:
        output += "*"

print(output)