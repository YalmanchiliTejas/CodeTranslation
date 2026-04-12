import sys
H,W = map(int, input().strip().split(' '))
lines = [line.strip() for line in sys.stdin if '#' in line]
lines = [''.join(l) for l in zip(*lines)]  # transpose
lines = [line for line in lines if '#' in line]
lines = [''.join(l) for l in zip(*lines)]
for line in lines:
  print(line)