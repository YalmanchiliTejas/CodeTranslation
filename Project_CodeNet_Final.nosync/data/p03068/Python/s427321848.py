N = int(input())
S = list(input())
K = int(input())
s = S[K - 1]
retval = ['*' if i != s else i for i in S]
print(''.join(retval))