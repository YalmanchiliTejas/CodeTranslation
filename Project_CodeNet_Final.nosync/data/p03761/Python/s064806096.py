def resolve():
    N = int(input())
    S = [input() for i in range(N)]
    import collections
    d = collections.Counter(S[0])
    for i in range(1, len(S)):
        d = (d & collections.Counter(S[i]))
    # print(d)
    s = ""
    for k in d.keys():
        for j in range(d[k]):
            s += k 
    print("".join(sorted(s)))
    



if '__main__' == __name__:
    resolve()