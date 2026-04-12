from collections import Counter
import copy
from itertools import combinations


def A(x):
  return 'Yes' if x >= 30 else 'No'


def main():
  x = int(input())
  print(A(x))


if __name__ == '__main__':
  main()
