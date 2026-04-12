from itertools import permutations
N, M = map(int, input().split())
T=[[]*N for _ in range(N)]
for _ in range(M):
  i ,j = map(int,input().split())
  T[i-1].append(j-1)
  T[j-1].append(i-1)

def main():
  ans = 0
  for p in permutations(range(1,N)): 
    c=0
    for n in p:
      if n not in T[c]:
        break
      c=n
    else:
      ans += 1
  print(ans)

if __name__ == "__main__":
  main()