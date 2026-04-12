N = int(input())
S = input()
K = int(input())

char = S[K-1]
new_S = ''
for i in range(N):
    if S[i] == char:
        new_S += char
    else:
        new_S += '*'

print(new_S)
