import sys

def main():
  input = sys.stdin.readline
  n = int(input())
  fes = [7, 5, 3]
  if n in fes:
    print('YES')
  else:
    print('NO')

if __name__ == '__main__':
  main()