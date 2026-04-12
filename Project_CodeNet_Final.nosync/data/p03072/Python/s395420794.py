def main():
  if 'get_ipython' not in globals():  
    N = input()
    X = list(map(int,input().split()))
  else:
    N = 5
    X = list(map(int, "9 5 6 8 4".split()))
    print(X)

  max = 0
  count = 0
  for value in X:
    if value >= max:
      count = count + 1
      max = value
    else:
      continue
  print(count)
      
  
main()