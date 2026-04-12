## coding: UTF-8
S = input()

ans = 'No'

if(S[0] != S[1]):
    ans = 'Yes'
if(S[1] != S[2]):
    ans = 'Yes'
if(S[0] != S[2]):
    ans = 'Yes'
print(ans)