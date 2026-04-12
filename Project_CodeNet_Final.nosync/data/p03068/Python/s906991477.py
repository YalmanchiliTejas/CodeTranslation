N = int(input())
S = input()
K = int(input())
l = S[K - 1]
result = ""
for s in S:
    if s != l:
         result += "*"
    else:
         result += s
print(result)
