n = int(input())
a = [input() for _ in range(n)]
al = [[0]*26 for _ in range(n)]
alph = 'abcdefghijklmnopqrstuvwxyz'
for i,s in enumerate(a):
    for k in s:
        al[i][alph.index(k)] += 1
        
ans = ''
for i in range(26):
    cnt = float('inf')
    for j in range(n):
        cnt = min(cnt, al[j][i])
    ans += alph[i]*cnt
ans = sorted(list(ans))
print(''.join(ans))