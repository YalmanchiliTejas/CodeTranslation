# coding: utf-8
# Your code here!

N = input()

S = input()

K = input()

ans = '';

for k,v in enumerate(S):
    
    
    if v == S[int(K)-1]:
        ans += v
    else:
        ans += '*' 

print(ans)