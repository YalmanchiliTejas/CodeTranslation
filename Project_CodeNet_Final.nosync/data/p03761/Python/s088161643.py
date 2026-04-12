from collections import Counter
n = int(input())
s = []
c_count = [[0] * n for _ in range(26)]
for i in range(n):
    count = Counter(input().rstrip())
    for key in count.keys():
        c_count[ord(key)-97][i] = count[key]

for i, item in enumerate(c_count):
    print(chr(i + 97) * min(item), end="")
print("")