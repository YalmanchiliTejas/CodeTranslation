n = int(input())
jisho = {}
s = list(input())
for w in s:
    if w in jisho:
        jisho[w] += 1
    else:
        jisho[w] = 1

for _ in range(n - 1):
    s = list(input())
    temp = {}
    for w in s:
        if w in temp:
            temp[w] += 1
        else:
            temp[w] = 1
    for key, val in jisho.items():
        if key in temp:
            jisho[key] = min(jisho[key], temp[key])
        else:
            jisho[key] = 0
kouho = []
start = ord("a")
for i in range(start, start + 26):
    w = chr(i)
    if w in jisho:
        kouho += str(w) * jisho[w]
    else:
        continue
print(*kouho, sep="")
