N = int(input())
S = input()
K = int(input())

key = S[K - 1]
ans = []

for char in S:
    if char != key:
        ans.append("*")
    else:
        ans.append(char)

print(*ans, sep="")