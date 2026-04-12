N, S, K = open(0)
K = S[int(K) - 1]
output = ""
for i in range(int(N)):
    if S[i] != K:
        output += "*"
    else:
        output += K
print(output)
