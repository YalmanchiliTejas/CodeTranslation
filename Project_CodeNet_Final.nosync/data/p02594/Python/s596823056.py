from sys import stdin
input = stdin.buffer.readline

print('YNeos'[int(input()) < 30 :: 2])