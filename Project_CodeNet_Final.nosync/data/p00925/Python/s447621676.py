s = '+'+input()
p = int(input())
n = 0
for a in [i+j for (i,j) in zip(s[::2], s[1::2])]:
    n = eval(str(n)+a)
f = 1 if n==p else 0
f += 2 if eval(s)==p else 0
print('ILMU'[f])
