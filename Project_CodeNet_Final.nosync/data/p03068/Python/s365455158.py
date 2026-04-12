N = int(input())
S = list(input())
K  = int(input())

l_replace = [s if S[K-1] in s else '*' for s in S]
print(''.join(l_replace))
