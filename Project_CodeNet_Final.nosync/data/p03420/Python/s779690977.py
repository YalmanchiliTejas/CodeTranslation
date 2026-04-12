import sys
input = sys.stdin.readline
def solve():
  n,k  =(int(i) for i in input().split())
  if n <= k:
    print(0)
    exit()
  else:

      ans = 0
      for b in range(k+1,n+1):
        if n%b == 0:
          ans += (n//b)*(b-k)
        else:
          if k == 0:
            ans += (n//b)*(b-k)+n%b
          else:
            ans += (n//b)*(b-k)+max(n%b-k+1,0)
  print(ans)
        
solve()
  