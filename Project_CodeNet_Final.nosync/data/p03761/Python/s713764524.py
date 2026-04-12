n = int(input())
tmp = [input() for _ in range(n)]
ans = []
for i in range(26):
    x=chr(ord('a')+i)
    cnt=50
    for s in tmp:
        cnt = min(cnt,s.count(x))
    else:
        ans.append(x*cnt)
print(''.join(ans))