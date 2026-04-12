s = [f for f in open(0).read().split() if '#' in f]
s = [''.join([s[j][i] for j in range(len(s))]) for i in range(len(s[0]))]
s = [f for f in s if '#' in f]
s = [''.join([s[j][i] for j in range(len(s))]) for i in range(len(s[0]))]
print(*s, sep='\n')