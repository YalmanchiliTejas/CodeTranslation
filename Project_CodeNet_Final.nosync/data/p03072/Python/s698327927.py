def main():
  n = int(input())
  #s = input()
  #s = input().split()
  h = list(map(int,input().split()))
  #c = [input().split() if i in range(n)]
  ans = 0
  a = 0
  
  for i in range(n):
    if a <= h[i]:
      ans += 1
      a = h[i]
  print(ans)
  
if __name__ == '__main__':
  main()