N = int(input())
S = input()
K = int(input())

target_char = S[K-1]
for num in range(N):
    if S[num] != target_char:
        S = S[:num] + '*' + S[num + 1:]

print(S)
