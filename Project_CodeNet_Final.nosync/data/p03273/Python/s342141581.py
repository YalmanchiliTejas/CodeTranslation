import sys

def main():
  input = sys.stdin.readline
  H, W = map(int, input().split())
  A = [str(input().strip()) for _ in range(H)]
  B = []
  for i in range(len(A)):
    if A[i] != '.'*W:
      B.append([str(c) for c in A[i]])

  C = [[0 for _ in range(len(B))] for _ in range(len(B[0]))]
  for i in range(len(B)):
    for j in range(len(B[0])):
      C[j][i] = B[i][j]
  
  D = []
  for i in range(len(C)):
    if ''.join(C[i]) != '.' * len(C[0]):
      D.append([str(c) for c in C[i]])
  
  E = [[0 for _ in range(len(D))] for _ in range(len(D[0]))]
  for i in range(len(D)):
    for j in range(len(D[0])):
      E[j][i] = D[i][j]

  for i in range(len(E)):
    print(''.join(E[i]))


if __name__ == '__main__':
  main()