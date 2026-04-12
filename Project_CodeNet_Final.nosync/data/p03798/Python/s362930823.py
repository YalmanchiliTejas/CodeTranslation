n = input()
s = raw_input()

def calc(x, y):
    S = [0]*n
    S[0] = x; S[1] = y
    for i in xrange(2, n):
        if (S[i-1] and s[i-1] == 'o') or (not S[i-1] and s[i-1] == 'x'):
            S[i] = S[i-2]
        else:
            S[i] = S[i-2] ^ 1
    if (S[n-1] and s[n-1] == 'o') or (not S[n-1] and s[n-1] == 'x'):
        if S[n-2] != S[0]:
            return ''
    else:
        if S[n-2] == S[0]:
            return ''
    if (S[0] and s[0] == 'o') or (not S[0] and s[0] == 'x'):
        if S[n-1] != S[1]:
            return ''
    else:
        if S[n-1] == S[1]:
            return ''
    return "".join(map("WS".__getitem__, S))

for i in xrange(4):
    res = calc(i & 1, (i>>1)&1)
    if res:
        print res
        break
else:
    print "-1"