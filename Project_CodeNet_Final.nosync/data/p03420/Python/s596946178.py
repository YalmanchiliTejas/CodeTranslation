N,K=map(int, input().split(" "))

out=0
if K==0:
    print(N*N)

else:
    for i in range(N):
        row=N-i
        if row <= K or row ==0:
            break
        out += (N-i-K) * int(N/row)
        if N%row >= K:
            out+=N%row-K+1

    print(out)
