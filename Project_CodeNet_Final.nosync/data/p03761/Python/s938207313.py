n = int(input())
s = [[i for i in input()] for j in range(n)]
ans = []

for k in set(s[0]):
    if all(k in s[i] for i in range(n)):
        count = s[0].count(k)
        for j in range(1,n):
            count = min(count, s[j].count(k))
        for l in range(count):
            ans.append(k)
print(''.join(sorted(ans)))