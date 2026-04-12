def main():
  a,b = map(int,input().split())
  ans = check(a,b)
  print(ans)
  
def check(n,m):
  if n == m:
    return "Yes"
  else:
    return "No"
main()