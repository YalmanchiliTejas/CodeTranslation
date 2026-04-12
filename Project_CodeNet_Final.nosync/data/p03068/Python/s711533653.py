N = int(input())
S = input()
K = int(input())
for c in S:
    if c != S[K-1]:
        print("*", end="")
    else:
        print(c, end="")
