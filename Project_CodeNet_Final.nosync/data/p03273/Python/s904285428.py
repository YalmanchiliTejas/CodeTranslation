"""
上手い方法思い付きませんでした（圧縮→行列転置→圧縮→行列転置は悪くなさそう）
～～～登場人物～～～
s：入力
ss：入力から行を圧縮したもの
　　（s[i]にピリオド以外のものがある場合にappendしたやつ）
  
answer：ssから頑張って列を圧縮したもの
       （ss[i][j]がすべてのjでピリオドだった場合のjをcolumn_compに格納
       　その後、column_compに含まれていないjにおいて、answer[i] += ss[i][j] ）

"""

h, w = [int(i) for i in input().split()]

s = []
for i in range(h):
  s.append(input())
#print(s)

#行を圧縮しましゅ
row = 0
ss = []
for i in range(h):
  if s[i].count(".") != w:
    ss.append(s[i])
    row += 1
#print(ss, row)
    
#列を圧縮しましゅ
column_comp = []
for j in range(w):
  period_count = 0
  for i in range(row):
#    print(s[j][i])
    if ss[i][j] == ".":
      period_count += 1
  if period_count == row:
    column_comp.append(j)
#    print(column_comp)

answer = ["" for i in range(row)]
for i in range(row):
  for j in range(w):
    if j not in column_comp:
      answer[i] += ss[i][j]
  print(answer[i])
