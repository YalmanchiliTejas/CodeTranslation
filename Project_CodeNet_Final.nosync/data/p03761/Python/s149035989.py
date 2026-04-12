from collections import deque,Counter

N = int(input())
S = [input() for _ in range(N)]

slist = "abcdefghijklmnopqrstuvwxyz"

anscnt = Counter()
for s in slist:
    anscnt[s] = 50

for line in S:
    tmp = Counter(line)
    for s in slist:
        anscnt[s] = min(anscnt[s],tmp[s])

ans = []
for s in slist:
    ans.append(s * anscnt[s])

print(*ans,sep="")