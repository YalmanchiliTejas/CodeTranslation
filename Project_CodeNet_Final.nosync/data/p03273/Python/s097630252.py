H,W = map(int,input().split())
ahw = [strlist for strlist in [[s for s in input()] for i in range(H)] if "#" in strlist]
tenti = []
for h in range(W):
   m =  [ah[h] for ah in ahw]
   if "#" in m:
       tenti.append(m)
for ahwnum in range(len(ahw)):
    print("".join([num[ahwnum] for num in tenti]))