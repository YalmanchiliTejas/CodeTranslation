N = int(input())
S = input()
K = int(input())

for c in S:
    if c == S[K - 1]:
        print(c, end="")
    else:
        print("*", end="")
print()
