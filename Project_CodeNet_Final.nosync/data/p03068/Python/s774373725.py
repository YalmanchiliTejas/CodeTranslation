N = int(input())
S = input()
K = int(input())
k_string = S[K-1:K]
i_string = 0
for i in range(N):
    i_string = S[i:i+1]
    if i_string != k_string:
        S = S.replace(i_string, "*")

print(S)
