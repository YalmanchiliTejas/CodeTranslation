H,W = [int(i) for i in input().split()]
table = []
for i in range(H):
  table.append(input())
 
table_ = []
for i in range(H):
  for j in range(W):
      if table[i][j] == '#':
          table_.append(table[i])
          break

ans = []
for i in range((W)):
    for j in range(len(table)):
        if table[j][i] == '#':
            ans.append(i)
            break

for line in table_:
    for i in ans:
        print(line[i],end = '')
    print()
