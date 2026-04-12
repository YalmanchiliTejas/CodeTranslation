N = int(input())
S = input()
K = int(input())

s1 = S[K-1]
out = ""
for i in range(N):
    if S[i] == s1:
        out += s1
    else:
        out += "*"

print(out)