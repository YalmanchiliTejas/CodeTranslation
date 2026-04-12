N = int(input())
S = list(input())
K = int(input())
string = S[K-1]
for i in range(len(S)):
    if S[i] != string:
        S[i] = "*"
print("".join(S))