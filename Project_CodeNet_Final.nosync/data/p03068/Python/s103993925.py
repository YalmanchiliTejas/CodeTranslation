N = int(input())
S = input()
K = int(input())

a = S[K-1]

output = ""
for i in range(N):
    if S[i] == a:
        output += a
    else:
        output += "*"

print(output)