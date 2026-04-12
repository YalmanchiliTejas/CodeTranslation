n = int(input())
sn = [[x for x in input()] for _ in range(n)]
print(''.join(s0*min(si.count(s0) for si in sn) for s0 in sorted(set(sn[0]))))
