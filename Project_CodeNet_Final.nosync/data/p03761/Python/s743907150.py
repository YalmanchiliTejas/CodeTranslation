n = int(input())
S = [input() for i in range(n)]
ans  = []
for i in range(26):
    x = chr(ord('a')+i)
    cnt = 50
    for s in S:
        cnt = min(cnt,s.count(x))
    ans.append(x*cnt)
print(''.join(ans))