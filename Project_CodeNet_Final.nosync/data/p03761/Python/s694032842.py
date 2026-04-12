az={chr(97+i):50 for i in range(26)}
for _ in[0]*int(input()):
    cnt={chr(97+i):0 for i in range(26)}
    for c in input():
        cnt[c]+=1
    for c in az:
        az[c]=min(az[c],cnt[c])
print(''.join(c*az[c]for c in sorted(az)))