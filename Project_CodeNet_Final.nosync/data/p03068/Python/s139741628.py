import copy 

n = int(input())
s = list(input())
k = int(input())

ans = s
for i in range(n):
    if ans[i] != s[k - 1]:
        ans[i] = '*'
print(''.join(ans))

