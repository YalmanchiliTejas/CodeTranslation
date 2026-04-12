N = int(input())
S = input()
K = int(input())
s = S[K - 1]
output = ""
for ss in S:
    if ss == s:
        output += s
    else:
        output += "*"

print(output)