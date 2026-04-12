#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main():
  input()
  heights = map(int, input().split())
  thres = 0
  count = 0

  for h in heights:
    if h >= thres:
      count += 1
      thres = h

  print(count)


if __name__ == '__main__':
  main()

