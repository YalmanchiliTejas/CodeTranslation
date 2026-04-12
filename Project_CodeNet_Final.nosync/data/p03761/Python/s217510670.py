N = int(input())
S = [input() for _ in range(N)]
abc = 'abcdefghijklmnopqrstuvwxyz'
count = [50]*26
for s in S:
    count_this = [0]*26
    for char in s:
        count_this[abc.index(char)] += 1
    for i in range(26):
        count[i] = min(count[i], count_this[i])
ans = ''
for i in range(26):
    ans += abc[i]*count[i]
print(ans)
