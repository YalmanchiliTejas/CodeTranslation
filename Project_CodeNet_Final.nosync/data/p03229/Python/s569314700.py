import numpy as np


def main():
  N, *A = map(int, open(0).read().split())
  A.sort()
  A = np.array(A)

  if N % 2:
    array1 = np.array([-2] * (N // 2) + [1] * 2 + [2] * (N // 2 - 1))
    array2 = np.array([-2] * (N // 2 - 1) + [-1] * 2 + [2] * (N // 2))
  
    ret1 = np.dot(A, array1)
    ret2 = np.dot(A, array2)
    ret = max(ret1, ret2)

  else:
    array1 = np.array([-2] * (N // 2 - 1) + [-1] + [1] + [2] * (N // 2 - 1))
  
    ret = np.dot(A, array1)
  
  print(ret)
  
if __name__=="__main__":
  main()