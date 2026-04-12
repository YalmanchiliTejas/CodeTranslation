import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

H, W = map(int, readline().split())
n = read().count(b'#')
print('Possible' if n == H + W - 1 else 'Impossible')