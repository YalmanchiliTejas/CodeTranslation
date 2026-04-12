N = int(raw_input())
S = raw_input()
K = int(raw_input())

s = S[K-1]

print "".join(map(lambda x: x if x==s else "*", list(S)))