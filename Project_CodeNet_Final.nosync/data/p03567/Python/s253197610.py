def main():
  str = input()
  for i in range(len(str) - 1):
    if str[i] == 'A' and str[i + 1] == 'C':
       print('Yes')
       return
  print('No')


if __name__ == '__main__':
  main()