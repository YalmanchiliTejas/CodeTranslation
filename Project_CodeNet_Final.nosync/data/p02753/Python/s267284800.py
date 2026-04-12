def main():
  x = input()

  num = 0
  for i in range(len(x)):
    if(x[0] != x[i]):
      num = 1

  if(num == 0):
    print('No')
  else:
    print('Yes')
    
if __name__ == '__main__':
  main()
