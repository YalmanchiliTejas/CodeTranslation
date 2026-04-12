N = int(input())
S = input()
K = int(input())
r = S[K-1]
print(''.join(list(map(lambda x: '*' if x!=r else r,S))))