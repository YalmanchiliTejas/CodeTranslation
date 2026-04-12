n, x = map(int, input().split())
b = [1]#l番目がレベルlの厚さを要素にもつ配列
p = [1]#l番目がレベルlのバーガーに入っているパティの数

for i in range(n):
  b.append(2*b[i]+3)
  p.append(2*p[i]+1)

def dfs(f, x):
  if x == 1:
    if f == 0:
      return 1
    else:
      return 0
  elif x <= b[f]//2:return dfs(f-1, x-1)
  elif x ==  b[f]//2 + 1: return p[f]//2+1
  elif x < b[f]: return p[f]//2 + 1 + dfs(f-1, x-b[f]//2-1)
  else:return p[f]
    
print(dfs(n, x))
  