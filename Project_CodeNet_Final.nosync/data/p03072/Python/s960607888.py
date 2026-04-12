# -*- coding: utf-8 -*-

def readInts():
  return [int(s) for s in input().split(" ")]

def main():
  N = readInts()[0]
  H = readInts()
  m = 0
  ans = 0
  for h in H:
    if h >= m:
      ans += 1
      m = h
  print(ans)

if __name__ == "__main__":
  main()
