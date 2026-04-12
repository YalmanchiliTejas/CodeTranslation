N,S,K=open(0).read().split()
print("".join(["*" if i!=S[int(K)-1] else i for i in S ]))