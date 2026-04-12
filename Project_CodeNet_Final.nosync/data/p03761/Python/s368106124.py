import collections

n = int(input())

dict = {}
for i in range(26):
    dict[chr(ord('a') + i)] = 50

for _ in range(n):
    S = input()
    for char in dict.keys():
        dict[char] = min(dict[char], S.count(char))
    
ans = ''
for char, num in sorted(dict.items()):
    ans += (char * num)

print(ans)
    