# -*- coding: utf-8 -*-

def readInts():
  return [int(s) for s in input().split(" ")]

def main():
  N = readInts()[0]
  S = input()
  K = readInts()[0]
  ans = ""
  for c in S:
    if c == S[K-1]:
      ans += c
    else:
      ans += "*"
  print(ans)

if __name__ == "__main__":
  main()
