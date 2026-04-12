mod = 10**9+7 

def main():
  n = int(input())
  a = list(map(int, input().split()))
  wa = sum(a)%mod
  ans = 0
  for i in range(n):
    wa -= a[i]%mod
    ans += (a[i]*wa)
    ans %= mod
  print(ans)
  
if __name__ == "__main__":
  main()