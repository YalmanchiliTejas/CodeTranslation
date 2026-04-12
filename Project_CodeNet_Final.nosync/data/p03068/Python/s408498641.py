N = int(input())
S = input()
K = int(input())
target = S[K-1]
S_new = ""
for c in S:
    if c == target:
        S_new += c
    else:
        S_new += "*"
print(S_new)