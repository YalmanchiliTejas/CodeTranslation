n = int(input())
S = [input() for _ in range(n)]
for c in map(chr, range(97+123)):
    print(c*min(s.count(c) for s in S), end='')
