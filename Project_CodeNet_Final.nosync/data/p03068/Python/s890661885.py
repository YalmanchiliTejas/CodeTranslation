N = int(input())
S = input()
K = int(input())

word = S[K-1]
chars = list(S)

rep = lambda c: "*" if c != word else c

newchars = [rep(c) for c in chars]
print("".join(newchars))