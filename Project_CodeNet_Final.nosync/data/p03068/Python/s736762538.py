#2019/09/27
N, L, K = [input() for i in range(3)]
L_replace = [("*" if (i != L[int(K)-1]) else  i) for i in L]
print("".join(L_replace))