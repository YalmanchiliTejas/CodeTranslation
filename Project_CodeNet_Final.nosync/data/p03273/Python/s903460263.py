l = [int(i) for i in input().split(" ")]
h = l[0]
w = l[1]

m = []
m_t = []
m_tt = []
# .のみの行を取り除く
for i in range(h):
    row = list(input())
    if "#" not in row:
        pass
    else:
        m.append(row)

# 転置して.のみの行を取り除く
for i in range(w):
    row = []
    for j in range(len(m)):
        row.append(m[j][i])
    if "#" not in row:
        pass
    else:
        m_t.append(row)

# 再び転置する
for i in range(len(m)):
    row = []
    for j in range(len(m_t)):
        row.append(m_t[j][i])
    m_tt.append(row)

for row in m_tt:
    print("".join(row))
