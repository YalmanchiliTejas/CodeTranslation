N = int(input())
S = input()
K = int(input())

ch = S[K-1]

x = [ch if ch == s else "*" for s in S]
print("".join(x))
