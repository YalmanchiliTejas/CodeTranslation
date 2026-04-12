n = int(input())
al=[chr(ord('a') + i) for i in range(26)]
INF = 10**9 + 1
#各アルファベットの出現回数の最小値
minAl = [INF for _ in range(26)]
#Cards = ["" for _ in range(n)]
for i in range(n):
    c = input()
    for j in range(26):
        minAl[j] = min(minAl[j],c.count(al[j]))
for i in range(26):
    if minAl[i] != INF:
        for j in range(minAl[i]):
            print(al[i], end="")