N = int(input())
S = input()
K = int(input())
print(''.join("*" if si != S[K - 1] else si for si in S))
