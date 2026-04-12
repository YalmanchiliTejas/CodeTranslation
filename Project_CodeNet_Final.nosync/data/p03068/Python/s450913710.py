N = int(input())
S = input()
K = int(input())

T = ''
x = S[K - 1]
for s in S:
    if s != x:
        T += '*'
    else:
        T += s
        
print(T)