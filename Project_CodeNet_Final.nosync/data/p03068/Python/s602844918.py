N = int(input())
S = input()
K = int(input())
key = S[K-1]
L = [i for i in S]
for i in range(N):
    if L[i] != key:
        L[i] = "*"
print("".join(L))