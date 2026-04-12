N = int(input())
S = input()
K = int(input())

target = S[K-1]
result = ""

for i in S:
    if i == target:
        result += i
    else:
        result += "*"

print(result)
