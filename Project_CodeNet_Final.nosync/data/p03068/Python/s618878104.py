# coding: utf-8
# Your# coding: utf-8
# Your code here!
N = int(input())
S = str(input())
K = int(input())
#rint(N,S,K)
 
WRITE = list(S)
CHARA = S[K-1]
#print(CHARA)
 
for i in range(N):
    if S[i] != CHARA:
        S = S[:i] + '*' + S[i+1:]
 
print(S) 
