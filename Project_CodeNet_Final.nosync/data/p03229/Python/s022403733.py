def main():
  N, *A = map(int, open(0).read().split())
  A.sort()

  if N % 2:
    array1 = [-2] * (N // 2) + [1] * 2 + [2] * (N // 2 - 1)
    array2 = [-2] * (N // 2 - 1) + [-1] * 2 + [2] * (N // 2)
  
    ret1 = 0
    ret2 = 0
    for i, j, k in zip(A, array1, array2):
      ret1 += i * j
      ret2 += i * k
    ret = max(ret1, ret2)

  else:
    array1 = [-2] * (N // 2 - 1) + [-1] + [1] + [2] * (N // 2 - 1)
  
    ret = 0
    for i, j in zip(A, array1):
      ret += i * j
  
  print(ret)

  
if __name__=="__main__":
  main()
