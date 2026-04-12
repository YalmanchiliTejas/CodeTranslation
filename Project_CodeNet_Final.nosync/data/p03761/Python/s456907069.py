import collections
n = int(input())

d = collections.Counter(input())
for i in range(n - 1):
    words = collections.Counter(input())
    for w in words.keys():
        d[w] = min(words[w], d[w])
        
    for w in d.keys():
        d[w] = min(words[w], d[w])

ans = []
for char in d.keys():
    for i in range(d[char]):
        ans.append(char)

ans.sort()

print(''.join(ans))