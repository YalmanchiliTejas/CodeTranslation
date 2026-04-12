N  = int(input())
slist = [input() for _ in range(N)]
abc = 'abcdefghijklmnopqrstuvwxyz'
l = [50] * 26
ans = ''
for i in range(26):
    for s in slist:
        l[i] = min(l[i],s.count(abc[i]))
for j in range(26):
    ans = ans + (abc[j] * l[j])
print(ans)
    