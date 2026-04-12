table = {}
while True:
    p, s = map(int, input().split(","))
    if p == 0:
        break
    table[p] = s
result = {v: i for i, v in enumerate(sorted(set(table.values()), reverse=True), start=1)}

try:
    while True:
        q = int(input())
        print(result[table[q]])
except EOFError:
    pass
