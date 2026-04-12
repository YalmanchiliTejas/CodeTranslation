n = int(input())
S = [input() for i in range(n)]
ans = ''

for alp in 'abcdefghijklmnopqrstuvwxyz':
    tmp = [s.count(alp) for s in S]
    ans += alp*min(tmp)
print(ans)