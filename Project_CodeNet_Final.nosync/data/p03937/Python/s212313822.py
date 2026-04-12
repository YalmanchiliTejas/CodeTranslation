h,w = map(int,input().split())
l = [list(input()) for _ in range(h)]
n = [0,1,0,-1]
m = [1,0,-1,0]


def dfs(a,b):
  if 0<=a+n[0] and a+n[0]<=w-1 and 0<=b+m[0] and b+m[0]<=h-1 and 0<=a+n[1] and a+n[1]<=w-1 and 0<=b+m[1] and b+m[1]<=h-1:
    if l[b+m[0]][a+n[0]]=="#" and l[b+m[1]][a+n[1]]=="#":
      return print("Impossible")
  for i in range(4):
    if 0<=a+n[i] and a+n[i]<=w-1 and 0<=b+m[i] and b+m[i]<=h-1:
      if l[b+m[i]][a+n[i]]=="#":
        if i==2 or i==3:
          return print("Impossible")

        elif a+n[i]==w-1 and b+m[i]==h-1:
          cou = 0
          for i in l:
            for j in i:
              if j=="#":
                cou += 1
          if cou==2:
            return print("Possible")
          else:
            return print("Impossible")
        else:
          l[b+m[i]][a+n[i]] = "."
          #print(l)
          return dfs(a+n[i],b+m[i])
  else:
    return print("Impossible")
      
    
        
dfs(0,0)