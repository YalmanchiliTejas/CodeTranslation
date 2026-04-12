N = int(input())
Ss = input()
K = int(input())

anss = []
for S in Ss:
    anss += ['*' if S != Ss[K-1] else S]

print(''.join(anss))
