N = input()
S=input()
K=int(input())
c = S[K - 1]

ans = ""

for char in S:
    ans += c if char == c else "*"

print(ans)