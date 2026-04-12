N = int(input())
S = input()
K = int(input())

x = S[K-1]

for i in range(len(S)):
    if not S[i] == x:
        S = S[:i] + "*" + S[i+1:]

print(S)
