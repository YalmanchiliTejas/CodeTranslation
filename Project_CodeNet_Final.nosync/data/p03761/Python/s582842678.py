n = int(input())
S = [list(input()) for _ in range(n)]

abc = 'abcdefghijklmnopqrstuvwxyz'
x = [50]*26
ans = []
for i in range(26):
    for j in S:
        x[i] = min(x[i],j.count(abc[i]))
for i in range(26):
    ans.append(abc[i]*x[i])
for i in range(26):
    print(ans[i],end='')
