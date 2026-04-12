#!/usr/bin/env python3

def solve(h,w,a):
  h_flags = [True]*h
  w_flags = [False]*w
  for i in range(h):
    if not "#" in a[i]:
      h_flags[i] = False
    for j in range(w):
      if a[i][j] == "#":
        w_flags[j] = True
  for i in range(h):
    if not h_flags[i]:
      continue
    for j in range(w):
      if w_flags[j]:
        print(a[i][j],end="")
    print("")
  return 



def main():
  H,W = map(int,input().split())
  a = [input() for _ in range(H)]
  solve(H,W,a)
  return

if __name__ == '__main__':
  main()
