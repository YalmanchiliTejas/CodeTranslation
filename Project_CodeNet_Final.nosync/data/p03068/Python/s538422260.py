N = int(input())
S = list(input())
K = int(input())
Selected = S[K-1]
for i,k in enumerate(S):
    if k != Selected:
        S[i] = "*"
strs = "".join(S)
print(strs)