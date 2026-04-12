n = int(input())
s = [sorted(input()) for i in range(n)]
ans = ''
while 1:
    flag = 0
    for c in 'abcdefghijklmnopqrstuvwxyz':
        if sum(c not in s[i] for i in range(n)) == 0:
            flag = 1
            for i in range(n):
                pos = s[i].index(c)
                s[i].pop(pos)
            break
    if not flag:
        break
    ans += c
print(ans)