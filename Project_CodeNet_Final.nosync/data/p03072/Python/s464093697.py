

def problem():
    N = int(input())
    H = list(map(int, input().split()))
    print(algorithm(N,H))


def algorithm(N: int, H):
  currentMax = H[0]
  counter = 1
  for i in range(1, N):
    if currentMax <= H[i]:
      counter += 1
      currentMax = H[i]
    
  return counter

problem()