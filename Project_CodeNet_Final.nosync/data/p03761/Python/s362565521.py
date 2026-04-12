table = {}
for i in range(ord('a'), ord('z') + 1):
    table[i] = []
n = int(raw_input().strip())
for i in range(0, n):
    s = raw_input().strip()
    for j in range(ord('a'), ord('z') + 1):
        table[j].append(s.count(chr(j)))
word = ""
for (key, val) in table.items():
    for i in range(0, min(val)):
        word += chr(key)
print word
