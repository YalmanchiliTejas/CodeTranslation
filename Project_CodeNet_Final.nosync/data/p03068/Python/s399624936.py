N = int(input())
S = input()
K = int(input())

result = ""
for si in S:
    result += "*" if si != S[K - 1] else si
print(result)
