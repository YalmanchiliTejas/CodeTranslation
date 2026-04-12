N = int(input())
S = input()
K = int(input())

out = ''
for i in range(N):
    if S[i] == S[K-1]:
        out = out + S[K-1]
    else:
        out = out + '*'
print(out)
