def replace_ast(N, S, K):
    rstr = S[K-1]
    outstr = ''
    for s in S:
        if s == rstr:
            outstr += s
        else:
            outstr += '*'
    print(outstr)


N = int(input())
S = str(input())
K = int(input())

replace_ast(N, S, K)