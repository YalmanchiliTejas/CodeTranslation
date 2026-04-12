import sys
import collections

n = int(input())


list = []
for i in range(26):
    list.append([0] * n)

for i in range(n):
    str = input()
    for c in str:
        a = ord(c) - ord("a")
        list[a][i] += 1

for i, l in enumerate(list):
    # print(i, l)
    print(chr(i + 97) * min(l), end="")
print()

sys.exit(0)
