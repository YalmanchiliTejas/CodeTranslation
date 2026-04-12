#!/usr/bin/env python3

# from numba import njit

# input = stdin.readline

dxdy = [[1,0],[0,1]]

# @njit
def solve(h,w,board):
  sharp_count = sum(x.count("#") for x in board)
  def dfs(y,x,gy,gx,cnt=1):
    if y == gy and x == gx:
      return cnt

    if not 0 <= y < h or not 0 <= x < w:
      return 0
    if board[y][x] == ".":
      return 0
    return  dfs(y+1,x,gy,gx,cnt+1) + dfs(y,x+1,gy,gx,cnt+1)
  
  return dfs(0,0,h-1,w-1) == sharp_count



def main():
  H,W = map(int,input().split())
  board = [input() for _ in range(H)]
  print("Possible" if solve(H,W,board) else "Impossible")
  return

if __name__ == '__main__':
  main()
