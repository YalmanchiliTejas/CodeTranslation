N = int(input())
S = [i for i in input()]
K = int(input())
char = S[K-1]
S = [char if s==char else "*" for s in S]
print("".join(S))