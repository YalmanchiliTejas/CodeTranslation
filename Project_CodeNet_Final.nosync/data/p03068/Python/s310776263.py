N = int(input())
S = input()
K = int(input())
S2 = ""
for c in S:
    if c == S[K-1]:
        S2 += c
    else:
        S2 += '*'
print(S2)