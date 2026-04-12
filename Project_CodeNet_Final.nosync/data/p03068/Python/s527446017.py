N = int(input())
S = input()
K = int(input())
letter = S[K-1]
print(''.join(s if s==letter else "*" for s in S ))