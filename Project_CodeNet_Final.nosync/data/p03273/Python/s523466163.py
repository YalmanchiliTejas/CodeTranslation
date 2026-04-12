#n = int(input())
h, w = map(int,input().split())
#ls = list(map(int,input().split()))
#ls = [list(map(int,input().split())) for i in range(n)]
ls = [input() for i in range(h)]
tmp = [i for i in ls if i.count('.') != w]
def t(tmp):
  ls = []
  for i in range(len(tmp[0])):
    ls.append("")
    for j in tmp:
      ls[i] += j[i]
  return ls
tmp = t(tmp)
ls = [i for i in tmp if i.count('.') != len(tmp[0])]
for i in t(ls):
  print(i)