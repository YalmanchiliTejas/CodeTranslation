n = int(input())
cmin = [114514 for i in range(26)]

for i in range(n):
    s = input()
    for j in range(26):
        cmin[j] = min(cmin[j], s.count(chr(ord('a') + j)))

for i in range(26):
    print(chr(ord('a') + i) * cmin[i], end='')

print()
