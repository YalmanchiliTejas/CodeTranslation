N = int(input())
S = list(input())
K = int(input())
un_replace_s = S[K-1]
out = "".join([s if s == un_replace_s else "*" for s in S])
print(out)
