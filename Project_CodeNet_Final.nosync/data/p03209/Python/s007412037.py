def main():
  n,x=map(int,input().split())
  from functools import lru_cache
  
  @lru_cache()
  def dfs(n,l,x): #レベルnバーガーで下からx番目までのパティの数
    if n==0:
      return 1
    else:
      t=(l-3)//2
      if x==1:
        return 0
      elif x<=l//2:
        return dfs(n-1,t,x-1)
      elif x==l//2+1:
        return dfs(n-1,t,x-2)+1
      else:
        return dfs(n-1,t,t)+1+dfs(n-1,t,x-t-2)
  print(dfs(n,2**(n+2)-3,x))
if __name__=='__main__':
  main()