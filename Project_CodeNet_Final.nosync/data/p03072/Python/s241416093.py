def solve(h_list):
  ans = 0
  h_max = h_list[0]
  for h in h_list:
    if h >= h_max:
      ans += 1
      h_max = h

  return ans

def main():
  n = int(input())
  h_list = list(map(int, input().split()))
  
  ans = solve(h_list)
  print(ans)

main()