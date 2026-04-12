#!/usr/bin/env python
# -*- coding: utf-8 -*-

N = int(input())
s = list(input())

def decide_i_plus_one(p, c, res):
  if c == 'S':
    if res == 'o':
      return p
    else:
      if p == 'S': return 'W'
      else:        return 'S'
  else:
    if res == 'o':
      if p == 'S': return 'W'
      else:        return 'S'
    else:
      return p

def valid(animals):
  # -2, -1, 0 のバリデーション
  if decide_i_plus_one(animals[-2], animals[-1], s[-1]) != animals[0]:
    return 0
  # -1, 0, 1 のバリデーション
  if decide_i_plus_one(animals[1], animals[0], s[0]) != animals[-1]:
    return 0

  # 0, 1, 2 のバリデーションは必要なし
  return 1

possible_pairs = [('S','S'), ('S','W'), ('W','S'), ('W','W')]
for (fst,snd) in possible_pairs:
  animals = []
  animals.append(fst)
  animals.append(snd)

  pi,ci = 0,1

  while 1:
    if ci == N-1:
      if valid(animals):
        print("".join(animals))
        exit(0)
      else:
        break

    n = decide_i_plus_one(animals[pi], animals[ci], s[ci])

    animals.append(n)
    pi += 1
    ci += 1

print("-1")