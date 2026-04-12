n = int(input())
tables = []
for i in range(n):
    tables.append([0 for i in range(26)])
    s = input()
    for ss in s:
        num = ord(ss) - 97
        tables[i][num] += 1

new_table = [0 for _ in range(26)] 
for i in range(26):
    num = i
    x = 10**9
    for j in range(n):
        x = min(x, tables[j][num])
    new_table[i] = x

ans = ""
for i in range(26):
    if new_table[i] > 0:
        ans += chr(i+97) * new_table[i]
print(ans)
        