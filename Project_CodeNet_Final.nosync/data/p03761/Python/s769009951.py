n = int(input())
p = [50 for i in range(26)]
for i in range(n):
    kar = input()
    for i in range(26):
        p[i] = min(p[i],kar.count(chr(ord("a") + i)))
for i in range(26):
    for j in range(p[i]):
        print(chr(ord("a") + i),end="")