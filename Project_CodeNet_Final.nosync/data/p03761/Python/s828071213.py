from collections import defaultdict
d=defaultdict(lambda: 51)
n=int(input())
for _ in range(n):
    s=input()
    for char in [chr(ord('a') + i) for i in range(26)]:
        d[char] = min(d[char],s.count(char))
ans=""
for char in [chr(ord('a') + i) for i in range(26)]:
    ans += char*d[char]
print(ans)