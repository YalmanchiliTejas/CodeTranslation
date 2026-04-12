MOD = 10 ** 9 + 7

def func(N,A):
  result = 0
  S = sum(A) % MOD
  for x in A:
    S -= x
    S %= MOD
    result += x * S
    result %= MOD
  result %= MOD
  return result

if __name__ == "__main__":
  N = int(input())
  A = list(map(int, input().split()))
  print(func(N,A))