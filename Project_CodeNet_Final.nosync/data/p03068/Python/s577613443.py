N = int(input())
S = input()
K = int(input())

k = S[K-1]
l = [''] * N

for i, s in enumerate(S):
    if s == k:
        l[i] = s
    else:
        l[i] = "*"
print("".join(l))