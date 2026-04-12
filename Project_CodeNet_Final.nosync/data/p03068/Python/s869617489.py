N = int(input())
S = input()
K = int(input())
T = ''

for s in S:
    if s != S[K-1]:
        s = '*'
    T += s
print(T)