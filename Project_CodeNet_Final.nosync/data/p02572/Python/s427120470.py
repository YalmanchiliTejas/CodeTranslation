mod = 1000000000+7

def product(N, As):
  result = 0
  summer = sum(As)
  for i in range(N-1):
    left = As[i]
    summer = summer - left
    result += left * summer
    
  return result % mod


if __name__ == "__main__":
  N = list(map(int, input().split()))
  As = list(map(int, input().split()))
  print(product(N[0], As))