from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(10 ** 7)

n = int(stdin.readline().rstrip())
s = [stdin.readline().rstrip() for _ in range(n)]

final = s[0]
for i in s:
    for j in final:
        if j not in i:
            final = final.replace(j,"")
        elif final.count(j) > i.count(j):
            final = list(final)
            for k in range(final.count(j)-i.count(j)):
                final.remove(j)
            final = "".join(final)
final = list(final)
final.sort()

print("".join(final))