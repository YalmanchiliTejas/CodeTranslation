#!/usr/bin/env python3


def solve(A, B, C, X, Y):

  def cost(cnt):
    a, b, c = cnt
    return a * A + b * B + c * C

  def useAB(cnt):
    return [max(0, cnt[0] - 1),
            max(0, cnt[1] - 1),
            cnt[2] + 2]

  cnt = [X, Y, 0]
  while cost(cnt) > cost(useAB(cnt)):
    cnt = useAB(cnt)

  return cost(cnt)


if __name__ == '__main__':
  A, B, C, X, Y = map(int, input().split())
  print(solve(A, B, C, X, Y))