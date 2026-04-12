h, w = map(int, input().split())

rows = [] #最初のfor文で、..だけの行を除く行を格納

for i in range(h):
  row = input()
  for c in row:
    if c == '#':
      rows.append(row)
      break
      
columns = []
column = ''
for i in range(w): #各列に対して行う
  for j in range(len(rows)): #行の数、つまり列の長さ
    if rows[j][i:i+1] == '#':
      for k in range(len(rows)):
        column += rows[k][i:i+1]
      columns.append(column)
      column = ''
      break
      
r = len(columns[0]) #最終行の数
ansrows = [''] * r
for i in range(r): #最終行の数だけ
  for j in range(len(columns)): #最終列の数だけ
  	ansrows[i] += columns[j][i]

#解答
for ans in ansrows: print(ans)