N = int(input())
S = input()
K = int(input())

c = S[K - 1]

result = "".join(x if x == c else "*" for x in S )

print(result)
