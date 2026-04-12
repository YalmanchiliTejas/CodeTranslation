N = int(input())
S = list(input())
K = int(input())
char = S[K-1]
n = 0
for N in S:
    if S[n] != char:
        S[n] = '*'
        n += 1
    else:
        n +=1
        
S_ = ''.join(S)
print(S_)