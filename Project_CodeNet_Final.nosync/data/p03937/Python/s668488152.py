H,W = map(int, input().split())
A = [input() for _ in range(H)]

total = sum([1 for a in A for s in a  if s=='#'])   
print('Possible' if total == W+H-1 else 'Impossible')