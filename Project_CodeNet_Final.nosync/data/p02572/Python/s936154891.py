n=int(input())
A=list(map(int,input().split()))

def twosekisum(A):
    return (sum(A)**2-sum([i**2 for i in A]))//2
print(twosekisum(A)%(10**9+7))