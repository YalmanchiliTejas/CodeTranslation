N = int(input())
S = input()
K = int(input())

s = S[K-1]
S_ = ''
for i,n in enumerate(S):
    if n==s:
        S_+=S[i]
    else:
        S_+='*'
print(S_)