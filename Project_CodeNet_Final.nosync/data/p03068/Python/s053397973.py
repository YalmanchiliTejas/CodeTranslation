N, S, K = [input() for i in range(3)]

s = "".join( [c if c == S[int(K)-1] else '*' for c in S] )
print(s)