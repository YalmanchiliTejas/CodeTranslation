N=input()
K=int(input())

def f(N,K):
    if K==0: return 1
    if N=="": return 0
    N=str(int(N))
    if N==0 : return 0
    l = len(N)
    n0 = int(N[0])
    return f(N[1:],K-1) + f("9"*(l-1),K-1)*(n0-1) + f("9"*(l-1),K)

print(f(N,K))