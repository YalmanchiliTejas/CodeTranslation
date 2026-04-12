N = int(input())
S = str(input())
K = int(input())
targc = S[K-1]
print("".join([c if c==targc else "*" for c in S]))
