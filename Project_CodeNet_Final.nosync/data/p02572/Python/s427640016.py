def resolve():
  N = int(input())
  A = [int(x) for x in input().split(" ")]
  # sumA = sum(A)
  reversedIntegraA = [0] * len(A)
  reversedIntegraA[-1] = A[-1]
  base = 10**9+7

  for i in reversed(range(len(A) - 1)):
    reversedIntegraA[i] = reversedIntegraA[i+1] + A[i]

  result = 0
  for i in range(len(A) - 1):
    result += A[i] * reversedIntegraA[i+1]
    if result > base:
      result %= base
  print(result)


if __name__ == "__main__":
  resolve()