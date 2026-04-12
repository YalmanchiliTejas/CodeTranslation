N = int(input())
S = list(input())
K = int(input())

target = S[K - 1]

result = ["*"] * N
for i in range(N):
    char = S[i]
    if char == target:
        result[i] = target
    else:
        result[i] = "*"
print("".join(result))
