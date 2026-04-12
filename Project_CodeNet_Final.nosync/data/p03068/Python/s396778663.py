N = int(input())
S = input().rstrip()
K = int(input())
str_k = S[K-1:K]

result = ""
for s in S:
    if s != str_k:
        result += '*'
    else:
        result += s

print(result)